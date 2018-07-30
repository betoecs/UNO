#include "AI.hpp"
#include <math.h>

///////////////////////////////////////
AI::AI(GameScene *scene) : Player(&scene->getDeck()), scene(scene), command(None), cardToSet(nullptr)
{
}

///////////////////////////////////////
void AI::think()
{
	if (command != None)
		return;

	CardEntity * card = chooseCard();
	if (card)
	{
		command = SetCard;
		cardToSet = card;
	}

	if (command == None)
		command = GetCard;

	scene->setTimeout(std::bind(&AI::doCommand, this), 1);
}

///////////////////////////////////////
void AI::doCommand()
{
	switch (command)
	{
		case GetCard: addCard(scene->getDeck().getCard(), true); break;
		case SetCard: scene->setCurrentCard(cardToSet->getCard(), this); removeCard(cardToSet);
	}

	cardToSet = nullptr;
	command = None;
}

///////////////////////////////////////
void AI::take(int number)
{
	for (int i = 0; i < number; i++)
		addCard(scene->getDeck().getCard(), true);
}

///////////////////////////////////////
Card::Color AI::chooseColor() const
{
	int redCount = getCardCountByColor(Card::Red);
	int blueCount = getCardCountByColor(Card::Blue);
	int greenCount = getCardCountByColor(Card::Green);
	int yellowCount = getCardCountByColor(Card::Yellow);

	int max = redCount;
	max = (max > blueCount) ? max : blueCount;
	max = (max > greenCount) ? max : greenCount;
	max = (max > yellowCount) ? max : yellowCount;

	std::vector<Card::Color> maxColors;

	if (max == redCount)
		maxColors.push_back(Card::Red);
	if (max == blueCount)
		maxColors.push_back(Card::Blue);
	if (max == greenCount)
		maxColors.push_back(Card::Green);
	if (max == yellowCount)
		maxColors.push_back(Card::Yellow);

	if (maxColors.size() == 1)
		return maxColors [0];

	Card::Color maxWeighingColor = Card::Red;
	int maxWeighing = 0;

	for (auto color : maxColors)
	{
		int colorWeighing = 0;
		for (auto cardEntity : getCardsByColor(color))
		{
			Card::Symbol cardSymbol = cardEntity->getCard()->getSymbol();
			int weighing;
			switch (cardSymbol)
			{
				case Card::Reverse: case Card::Skip: weighing = 1; break;
				case Card::Take2: weighing = 3; break;
				default: weighing = 2;
			}

			colorWeighing += weighing;
		}

		if (colorWeighing >= maxWeighing)
		{
			maxWeighing = colorWeighing;
			maxWeighingColor = color;
		}
	}
	return maxWeighingColor;
}

///////////////////////////////////////
CardEntity * AI::chooseCard()
{
	std::vector <CardEntity *> cardsByColor = getCardsByColor(scene->getCurrentCard()->getColor());
	std::vector <CardEntity *> cardsBySymbol = getCardsBySymbol(scene->getCurrentCard()->getSymbol());

	int max = 0;
	CardEntity *selectedCard = nullptr;
	for (auto card : cardsByColor)
	{
		if (card->getCard()->getSymbol()== Card::Take2 || card->getCard()->getSymbol()== Card::Skip || card->getCard()->getSymbol()== Card::Reverse)
		{
			if (cardsByColor.size() > 1)
			{
				selectedCard = card;
				break;
			}
		}

		int aux = getCardCountBySymbol(card->getCard()->getSymbol());
		if (aux > max)
		{
			max = aux;
			selectedCard = card;
		}
	}

	if (selectedCard)
		return selectedCard;

	max = 0;
	for (auto card : cardsBySymbol)
	{
		int aux = getCardCountByColor(card->getCard()->getColor());
		if (aux > max)
		{
			max = aux;
			selectedCard = card;
		}
	}

	if (selectedCard)
		return selectedCard;

	std::vector <CardEntity *> wild = getCardsBySymbol(Card::Wild);
	if (wild.size() != 0)
		return wild [0];

	std::vector <CardEntity *> take4 = getCardsBySymbol(Card::Take4);
	if (take4.size() != 0)
		return take4 [0];

	return nullptr;
}

///////////////////////////////////////
int AI::getCardCountByColor(Card::Color color) const
{
	int colorCount = 0;
	for (auto cardEntity : getCards())
	{
		if (cardEntity->getCard()->getColor() == color)
			colorCount++;
	}
	return colorCount;
}

///////////////////////////////////////
int AI::getCardCountBySymbol(Card::Symbol symbol) const
{
	int symbolCount = 0;
	for (auto cardEntity : getCards())
	{
		if (cardEntity->getCard()->getSymbol() == symbol)
			symbolCount++;
	}
	return symbolCount;
}

///////////////////////////////////////
std::vector <CardEntity *> AI::getCardsByColor(Card::Color color) const
{
	std::vector <CardEntity *> cards;
	for (auto cardEntity : getCards())
	{
		if (cardEntity->getCard()->getColor() == color)
			cards.push_back(cardEntity);
	}
	return cards;
}

///////////////////////////////////////
std::vector <CardEntity *> AI::getCardsBySymbol(Card::Symbol symbol) const
{
	std::vector <CardEntity *> cards;
	for (auto cardEntity : getCards())
	{
		if (cardEntity->getCard()->getSymbol() == symbol)
			cards.push_back(cardEntity);
	}
	return cards;
}

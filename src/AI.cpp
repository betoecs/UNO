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

	for (auto card : getCards())
	{
		if (scene->getCurrentCard()->getCompatibility(*card->getCard()) != Card::None)
		{
			command = SetCard;
			cardToSet = card;
			break;
		}
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
		case GetCard: addCard(scene->getDeck().getCard(), false); break;
		case SetCard: scene->setCurrentCard(cardToSet->getCard(), this); removeCard(cardToSet);
	}

	cardToSet = nullptr;
	command = None;
}

///////////////////////////////////////
void AI::take(int number)
{
	for (int i = 0; i < number; i++)
		addCard(scene->getDeck().getCard(), false);
}

///////////////////////////////////////
Card::Color AI::chooseColor() const
{
	int redCount = getCardCount(Card::Red);
	int blueCount = getCardCount(Card::Blue);
	int greenCount = getCardCount(Card::Green);
	int yellowCount = getCardCount(Card::Yellow);

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
	{
		printf("I chosen the color %d because it has more cards than the others\n", maxColors[0]);
		return maxColors [0];
	}

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

	printf("I chosen the color %d because it has a %d weighning\n", maxWeighingColor, maxWeighing);
	return maxWeighingColor;
}

///////////////////////////////////////
int AI::getCardCount(Card::Color color) const
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

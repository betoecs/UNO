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
		case GetCard: addCard(scene->getDeck().getCard(), true); break;
		case SetCard: scene->setCurrentCard(cardToSet->getCard(), this); removeCard(cardToSet);
	}

	cardToSet = nullptr;
	command = None;
}

///////////////////////////////////////
Card::Color AI::chooseColor() const
{
	return Card::Color(rand() % 4);
}

///////////////////////////////////////
void AI::take(int number)
{
	for (int i = 0; i < number; i++)
		addCard(scene->getDeck().getCard(), true);
}

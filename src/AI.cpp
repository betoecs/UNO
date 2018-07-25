#include "AI.hpp"

///////////////////////////////////////
AI::AI(GameScene *scene) : scene(scene), command(None), cardToSet(nullptr)
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

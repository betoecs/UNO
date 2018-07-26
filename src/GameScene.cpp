#include "GameScene.hpp"
#include "Controller.hpp"
#include "ColorSelectorEntity.hpp"
#include "AI.hpp"

extern Vector2D windowSize;

///////////////////////////////////////
void GameScene::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 0));
	connectToEvent(sf::Event::MouseButtonPressed, std::bind(&GameScene::onClick, this, std::placeholders::_1));
	setBackgroundColor(Color("#fff"));

	// Deck card entity
	deckCardEntity = new CardEntity(nullptr, true);
	deckCardEntity->setPosition(windowSize.x * 0.15f, windowSize.y * 0.5f);
	addChild(deckCardEntity);

	// Player and AI
	player = new Controller(this);
	player->setPosition(windowSize.x * 0.5f, windowSize.y * 0.9f);
	addChild(player);

	ai = new AI(this);
	ai->setPosition(windowSize.x * 0.5f, windowSize.y * 0.1f);
	addChild(ai);

	for (int i = 0; i < 7; i++)
	{
		player->addCard(deck.getCard(), false);
		ai->addCard(deck.getCard(), true);
	}

	// Current card entity
	currentCardEntity = new CardEntity(deck.getCard(), false);
	currentCardEntity->setPosition(windowSize * 0.5f);
	addChild(currentCardEntity);

	currentPlayer = player;
}

///////////////////////////////////////
void GameScene::onClose(int scene)
{
	directorAction.type = DirectorAction::PopScene;
}

///////////////////////////////////////
void GameScene::onUpdate(float frameTime)
{
	if (ai == currentPlayer)
		ai->think();
}

///////////////////////////////////////
Deck & GameScene::getDeck()
{
	return deck;
}

///////////////////////////////////////
bool GameScene::setCurrentCard(Card *card, Player *applicant)
{
	if (applicant != currentPlayer || currentCardEntity->getCard()->getCompatibility(*card) == Card::None)
		return false;

	currentCardEntity->getCard()->setUsed(false);
	currentCardEntity->setCard(card);

	if (currentCardEntity->getCard()->getSymbol() == Card::Skip || currentCardEntity->getCard()->getSymbol() == Card::Reverse)
		return true;

	if (currentCardEntity->getCard()->getSymbol() == Card::Take2)
	{
		if(currentPlayer == player)
		{
				ai->addCard(deck.getCard(), true);
				ai->addCard(deck.getCard(), true);
		}
		else
		{
				player->addCard(deck.getCard(), false);
				player->addCard(deck.getCard(), false);
		}
		return true;
	}

	if (currentPlayer->getCards().size() > 1)
		currentPlayer = (applicant == player) ? ai : player;

	else
		close(0);

	return true;
}

///////////////////////////////////////
const Card * GameScene::getCurrentCard() const
{
	return currentCardEntity->getCard();
}

///////////////////////////////////////
void GameScene::onClick(const sf::Event &event)
{
	if (player == currentPlayer && deckCardEntity->getBoundingBox().contains(event.mouseButton.x, event.mouseButton.y))
		player->addCard(deck.getCard(), false);
}

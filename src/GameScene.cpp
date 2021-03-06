#include "AI.hpp"
#include "GameScene.hpp"
#include "Controller.hpp"
#include "GameOverScene.hpp"

#include <LK/Text.hpp>

extern Vector2D windowSize;

///////////////////////////////////////
void GameScene::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 1));
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

	player->take(7);
	ai->take(7);

	// Current card entity
	currentCardEntity = new CardEntity(deck.getCard(), false);
	takeInitialCard();
	currentCardEntity->setPosition(windowSize * 0.5f);
	addChild(currentCardEntity);

	currentPlayer = player;
	nextPlayer = ai;

	// Color selector entity
	colorSelector = new ColorSelectorEntity;
	colorSelector->setVisible(false);
	colorSelector->setPosition(windowSize * 0.5f);
	colorSelector->onSelect.connect(std::bind(&GameScene::onSelectedColor, this, std::placeholders::_1));
	addChild(colorSelector);

	// Player turn indicator
	turnIndicator = new TurnIndicator();
	turnIndicator->setPosition(windowSize.x * 0.9, windowSize.y * 0.5f);
	turnIndicator->addPlayer("AI");
	turnIndicator->addPlayer("Player");
	turnIndicator->setCurrentPlayer(1);
	addChild(turnIndicator);
}

///////////////////////////////////////
void GameScene::onReopen()
{
	player->removeCards();
	ai->removeCards();

	deck.reset();
	player->take(7);
	ai->take(7);
	currentPlayer = player;
	turnIndicator->setCurrentPlayer(1);

	currentCardEntity->setCard(deck.getCard());
	takeInitialCard();
}

///////////////////////////////////////
void GameScene::onClose(int scene)
{
	bool winner = (player->getCards().size() == 1) ? true : false;

	switch (scene)
	{
		case 0: directorAction.type = DirectorAction::PopScene; break;
		case 1: directorAction.type = DirectorAction::PushScene; directorAction.scene = new GameOverScene(winner);
	}
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
	if (currentCardEntity->getCard()->getSymbol() == Card::Wild || currentCardEntity->getCard()->getSymbol() == Card::Take4 )
		currentCardEntity->getCard()->setColor(Card::NoColor);
	currentCardEntity->setCard(card);
	Card::Symbol cardSymbol = currentCardEntity->getCard()->getSymbol();

	if (cardSymbol == Card::Take2)
	{
		nextPlayer->take(2);
	}
	else if (cardSymbol == Card::Wild || cardSymbol == Card::Take4)
	{
		if (currentPlayer == player)
		{
			currentPlayer = nullptr;
			colorSelector->setVisible(true);
		}
		else
		{
			currentCardEntity->getCard()->setColor(ai->chooseColor());
		}

		if (cardSymbol == Card::Take4)
			nextPlayer->take(4);
	}

	if (currentPlayer)
	{
		if (currentPlayer->getCards().size() > 1)
		{
			if (cardSymbol != Card::Skip && cardSymbol != Card::Reverse && cardSymbol != Card::Wild &&
				cardSymbol != Card::Take4 && cardSymbol != Card::Take2)
			{
				nextPlayer = currentPlayer;
				currentPlayer = (applicant == player) ? ai : player;
				turnIndicator->changeTurn();
			}
		}
		else
			close(1);
	}

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

///////////////////////////////////////
void GameScene::onSelectedColor(Card::Color color)
{
	currentCardEntity->getCard()->setColor(color);
	currentPlayer = player;
}

///////////////////////////////////////
void GameScene::takeInitialCard()
{
	while (currentCardEntity->getCard()->getSymbol() == Card::Wild || currentCardEntity->getCard()->getSymbol() == Card::Take4)
	{
		currentCardEntity->getCard()->setUsed(false);
		currentCardEntity->setCard(deck.getCard());
	}
}

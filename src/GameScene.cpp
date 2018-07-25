#include "GameScene.hpp"
#include "AI.hpp"

extern Vector2D windowSize;

///////////////////////////////////////
void GameScene::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 0));
	setBackgroundColor(Color("#fff"));

	// Deck card entity
	auto deckCard = new CardEntity(nullptr, true);
	deckCard->setPosition(windowSize.x * 0.15f, windowSize.y * 0.5f);
	addChild(deckCard);

	// Player and AI
	auto player = new Player;
	player->setPosition(windowSize.x * 0.5f, windowSize.y * 0.9f);
	addChild(player);

	auto ai = new AI;
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
}

///////////////////////////////////////
void GameScene::onClose(int scene)
{
	directorAction.type = DirectorAction::PopScene;
}

///////////////////////////////////////
bool GameScene::setCurrentCard(Card *card)
{
	if (currentCardEntity->getCard()->getCompatibility(*card) == Card::None)
		return false;

	currentCardEntity->setCard(card);
	return true;
}

///////////////////////////////////////
const Card * GameScene::getCurrentCard() const
{
	return currentCardEntity->getCard();
}

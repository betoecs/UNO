#include "GameScene.hpp"
#include "CardEntity.hpp"
#include "Controller.hpp"
#include "AI.hpp"

extern Vector2D windowSize;

///////////////////////////////////////
void GameScene::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 0));
	setBackgroundColor(Color("#fff"));

	auto deckCard = new CardEntity(nullptr, true);
	deckCard->setPosition(windowSize.x * 0.15f, windowSize.y * 0.5f);
	addChild(deckCard);

	auto player = new Controller(this);
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
}

///////////////////////////////////////
void GameScene::onClose(int scene)
{
	directorAction.type = DirectorAction::PopScene;
}

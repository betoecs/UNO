#include "GameScene.hpp"

extern Vector2D windowSize;

///////////////////////////////////////
void GameScene::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 0));
	setBackgroundColor(Color("#fff"));
}

///////////////////////////////////////
void GameScene::onClose(int scene)
{
	directorAction.type = DirectorAction::PopScene;
}

#include "FooScene.hpp"
#include <LK/Sprite.hpp>

void FooScene::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 0));

	auto sprite = new Sprite("big-image.png");
	sprite->setOriginCenter();
	addChild(sprite);

	camera = getCamera(Scene::defaultCamera);
	camera->setCenter(0, 0);
	camera->setBoundingBox(Rect(-1500, -100, 3000, 200));
	connectToKeyPressed(sf::Keyboard::R, std::bind(&Camera::centerAtBoundingBox, camera));
}

void FooScene::onClose(int scene)
{
}

void FooScene::onUpdate(float frameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) camera->move(10, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) camera->move(-10, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) camera->move(0, -10);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) camera->move(0, 10);
}

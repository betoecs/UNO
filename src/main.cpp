#include <LK/AssetsManager.hpp>
#include <LK/Director.hpp>
using namespace lk;

#include "Assets.h"
#include "MainMenu.hpp"

Vector2D windowSize(1366, 768);

int main()
{
	AssetsManager::assetsPath = ASSETS;
	auto &director = Director::getInstance();
	director.create(sf::VideoMode::getDesktopMode(), "uno", sf::Style::Fullscreen);
	director.setFramerateLimit(60);
	director.setVerticalSyncEnabled(true);

	return director.startGame(new MainMenu);
}

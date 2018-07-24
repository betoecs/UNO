#include "MainMenu.hpp"
#include "ConfigMenu.hpp"
#include <LK/Button.hpp>
#include <LK/LinearLayout.hpp>

extern Vector2D windowSize;

///////////////////////////////////////
void MainMenu::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 0));
	setBackgroundColor(Color("#fff"));

	auto font = AssetsManager::getFont("riffic.otf");

	auto title = new Text("UNO", font, 130);
	title->setBold(true);
	title->setColor(Color("#feed0d"));
	title->setOriginCenter();
	title->setOutlineThickness(5);
	title->setPosition(windowSize.x * 0.5f, windowSize.y * 0.15);
	addChild(title);

	auto scaleUpButton = [&](Button *button) { button->setScale(1.1, 1.1); };
	auto scaleDownButton = [&](Button *button) { button->setScale(1, 1); };

	auto mainButtonsLayout = new LinearLayout(30, LinearLayout::Vertical);
	mainButtonsLayout->setPosition(windowSize.x * 0.5f, windowSize.y * 0.55f);
	addChild(mainButtonsLayout);

	auto playButton = new Button("PLAY", font, 50);
	playButton->setOutlineThickness(2);
	playButton->setColor(Color("#1fa8ec"));
	playButton->onMouseOver.connect(std::bind(scaleUpButton, playButton));
	playButton->onMouseLeave.connect(std::bind(scaleDownButton, playButton));
	playButton->onClick.connect(std::bind(&Scene::close, this, 1));
	mainButtonsLayout->addChild(playButton);

	auto quitButton = new Button("QUIT", font, 50);
	quitButton->setOutlineThickness(2);
	quitButton->setColor(Color("#f12323"));
	quitButton->onMouseOver.connect(std::bind(scaleUpButton, quitButton));
	quitButton->onMouseLeave.connect(std::bind(scaleDownButton, quitButton));
	quitButton->onClick.connect(std::bind(&Scene::close, this, 0));
	mainButtonsLayout->addChild(quitButton);
}

///////////////////////////////////////
void MainMenu::onClose(int scene)
{
	switch (scene)
	{
		case 0: directorAction.type = DirectorAction::CloseGame; break;
		case 1: directorAction.type = DirectorAction::PushScene; directorAction.scene = new ConfigMenu;
	}
}

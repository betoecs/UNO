#include "ConfigMenu.hpp"
#include <LK/Button.hpp>
#include <LK/LinearLayout.hpp>

extern Vector2D windowSize;

///////////////////////////////////////
void ConfigMenu::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 0));
	setBackgroundColor(Color("#fff"));

	auto font = AssetsManager::getFont("riffic.otf");

	auto title = new Text("IA Settings", font, 130);
	title->setBold(true);
	title->setColor(Color("#feed0d"));
	title->setOriginCenter();
	title->setOutlineThickness(5);
	title->setPosition(windowSize.x * 0.5f, windowSize.y * 0.15);
	addChild(title);

	auto buttonsLayout = new LinearLayout(30, LinearLayout::Vertical);
	buttonsLayout->setPosition(windowSize.x * 0.5f, windowSize.y * 0.55f);
	addChild(buttonsLayout);

	auto changeCheckboxTexture = [&](Button *button) { button->setTexture(button->isToggled() ? "checked.png" : "unchecked.png"); };

	auto symbolsButton = new Button("unchecked.png", "SYMBOLS", font, 50, true);
	symbolsButton->setTextColor(Color("#1fa8ec"));
	symbolsButton->setOutlineThickness(2);
	symbolsButton->onToggled.connect(std::bind(changeCheckboxTexture, symbolsButton));
	buttonsLayout->addChild(symbolsButton);
}

///////////////////////////////////////
void ConfigMenu::onClose(int scene)
{
	switch (scene)
	{
		case 0: directorAction.type = DirectorAction::PopScene; break;
		//case 1: directorAction.type = DirectorAction::PushScene; directorAction.scene = new ConfigMenu;
	}
}

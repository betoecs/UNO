#include "ConfigMenu.hpp"
#include "GameScene.hpp"
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

	auto scaleUpButton = [&](Button *button) { button->setScale(1.1, 1.1); };
	auto scaleDownButton = [&](Button *button) { button->setScale(1, 1); };
	auto changeCheckboxTexture = [&](Button *button) { button->setTexture(button->isToggled() ? "checked.png" : "unchecked.png"); };
	int spaceBetween = 15;

	auto plusButton = new Button("checked.png", "+2 / +4", font, 50, true, Button::Checkbox);
	plusButton->setSpaceBetween(spaceBetween);
	plusButton->toggle();
	plusButton->setTextColor(Color("#1fa8ec"));
	plusButton->setOutlineThickness(2);
	plusButton->onToggled.connect(std::bind(changeCheckboxTexture, plusButton));
	buttonsLayout->addChild(plusButton);

	auto symbolsButton = new Button("checked.png", "SYMBOLS", font, 50, true, Button::Checkbox);
	symbolsButton->setSpaceBetween(spaceBetween);
	symbolsButton->toggle();
	symbolsButton->setTextColor(Color("#1fa8ec"));
	symbolsButton->setOutlineThickness(2);
	symbolsButton->onToggled.connect(std::bind(changeCheckboxTexture, symbolsButton));
	buttonsLayout->addChild(symbolsButton);

	auto wildcardButton = new Button("checked.png", "WILDCARD", font, 50, true, Button::Checkbox);
	wildcardButton->setSpaceBetween(spaceBetween);
	wildcardButton->toggle();
	wildcardButton->setTextColor(Color("#1fa8ec"));
	wildcardButton->setOutlineThickness(2);
	wildcardButton->onToggled.connect(std::bind(changeCheckboxTexture, wildcardButton));
	buttonsLayout->addChild(wildcardButton);

	auto reverseButton = new Button("checked.png", "REVERSE / CANCEL", font, 50, true, Button::Checkbox);
	reverseButton->setSpaceBetween(spaceBetween);
	reverseButton->toggle();
	reverseButton->setTextColor(Color("#1fa8ec"));
	reverseButton->setOutlineThickness(2);
	reverseButton->onToggled.connect(std::bind(changeCheckboxTexture, reverseButton));
	buttonsLayout->addChild(reverseButton);

	auto backButton = new Button("BACK", font, 50);
	backButton->setOutlineThickness(2);
	backButton->setColor(Color("#69ec2c"));
	backButton->setPosition(windowSize.x * 0.1, windowSize.y * 0.9);
	backButton->onMouseOver.connect(std::bind(scaleUpButton, backButton));
	backButton->onMouseLeave.connect(std::bind(scaleDownButton, backButton));
	backButton->onClick.connect(std::bind(&Scene::close, this, 0));
	addChild(backButton);

	auto nextButton = new Button("NEXT", font, 50);
	nextButton->setOutlineThickness(2);
	nextButton->setColor(Color("#69ec2c"));
	nextButton->setPosition(windowSize.x * 0.9, windowSize.y * 0.9);
	nextButton->onMouseOver.connect(std::bind(scaleUpButton, nextButton));
	nextButton->onMouseLeave.connect(std::bind(scaleDownButton, nextButton));
	nextButton->onClick.connect(std::bind(&Scene::close, this, 1));
	addChild(nextButton);
}

///////////////////////////////////////
void ConfigMenu::onClose(int scene)
{
	switch (scene)
	{
		case 0: directorAction.type = DirectorAction::PopScene; break;
		case 1: directorAction.type = DirectorAction::PushScene; directorAction.scene = new GameScene;
	}
}

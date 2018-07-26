#include "ColorSelectorEntity.hpp"
#include <LK/Button.hpp>

///////////////////////////////
ColorSelectorEntity::ColorSelectorEntity()
{
	auto sprite = new Sprite("choose-color-background.png");
	sprite->setOriginCenter();
	addChild(sprite);

	auto scaleUpButton = [&](Button *button) { button->setScale(1.1, 1.1); };
	auto scaleDownButton = [&](Button *button) { button->setScale(1, 1); };

	auto yellowButton = new Button;
	yellowButton->setTexture("yellow-button.png");
	yellowButton->onMouseOver.connect(std::bind(scaleUpButton, yellowButton));
	yellowButton->onMouseLeave.connect(std::bind(scaleDownButton, yellowButton));
	yellowButton->onClick.connect(std::bind(&ColorSelectorEntity::onClick, this, Card::Yellow));
	addChild(yellowButton);

	const auto &buttonHalfSize = Vector2D(100, 100) * 0.5f;
	int margin = 10;
	yellowButton->setPosition(-buttonHalfSize.x - margin, -buttonHalfSize.y - margin);

	auto redButton = new Button;
	redButton->setTexture("red-button.png");
	redButton->setPosition(buttonHalfSize.x + margin, -buttonHalfSize.y - margin);
	redButton->onMouseOver.connect(std::bind(scaleUpButton, redButton));
	redButton->onMouseLeave.connect(std::bind(scaleDownButton, redButton));
	redButton->onClick.connect(std::bind(&ColorSelectorEntity::onClick, this, Card::Red));
	addChild(redButton);

	auto greenButton = new Button;
	greenButton->setTexture("green-button.png");
	greenButton->setPosition(-buttonHalfSize.x - margin, buttonHalfSize.y + margin);
	greenButton->onMouseOver.connect(std::bind(scaleUpButton, greenButton));
	greenButton->onMouseLeave.connect(std::bind(scaleDownButton, greenButton));
	greenButton->onClick.connect(std::bind(&ColorSelectorEntity::onClick, this, Card::Green));
	addChild(greenButton);

	auto blueButton = new Button;
	blueButton->setTexture("blue-button.png");
	blueButton->setPosition(buttonHalfSize.x + margin, buttonHalfSize.y + margin);
	blueButton->onMouseOver.connect(std::bind(scaleUpButton, blueButton));
	blueButton->onMouseLeave.connect(std::bind(scaleDownButton, blueButton));
	blueButton->onClick.connect(std::bind(&ColorSelectorEntity::onClick, this, Card::Blue));
	addChild(blueButton);
}

///////////////////////////////
void ColorSelectorEntity::onClick(Card::Color selectedColor)
{
	onSelect.emit(selectedColor);
	setVisible(false);
}

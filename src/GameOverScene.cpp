#include "GameScene.hpp"
#include "MainMenu.hpp"
#include "GameOverScene.hpp"
#include <LK/Button.hpp>
#include <LK/LinearLayout.hpp>

extern Vector2D windowSize;

///////////////////////////////////////
GameOverScene::GameOverScene (bool winner) : winner(winner)
{

}

///////////////////////////////////////
void GameOverScene::onCreate()
{
	connectToKeyPressed(sf::Keyboard::Escape, std::bind(&Scene::close, this, 0));
	setBackgroundColor(Color("#fff"));

	auto font = AssetsManager::getFont("riffic.otf");

	auto title = new Text("Game Over", font, 130);
	title->setBold(true);
	title->setColor(Color("#feed0d"));
	title->setOriginCenter();
	title->setOutlineThickness(5);
	title->setPosition(windowSize.x * 0.5f, windowSize.y * 0.15);
	addChild(title);

    std::string isWinner;
    if (winner)
         isWinner = "You Win!!  :)";
    else
        isWinner = "You Lose :(";

    auto winnerText = new Text(isWinner, font, 110);
	winnerText->setBold(true);
	winnerText->setColor(Color("#1fa8ec"));
	winnerText->setOriginCenter();
	winnerText->setOutlineThickness(5);
	winnerText->setPosition(windowSize.x * 0.5f, windowSize.y * 0.5);
	addChild(winnerText);

	auto scaleUpButton = [&](Button *button) { button->setScale(1.1, 1.1); };
	auto scaleDownButton = [&](Button *button) { button->setScale(1, 1); };

    auto mainButtonsLayout = new LinearLayout(1000, LinearLayout::Horizontal);
    mainButtonsLayout->setPosition(windowSize.x * 0.5f, windowSize.y * 0.9f);
    addChild(mainButtonsLayout);

    auto playAgainButton = new Button("back-icon.png","",font, 50);
    playAgainButton->setOutlineThickness(2);
    playAgainButton->onMouseOver.connect(std::bind(scaleUpButton, playAgainButton));
    playAgainButton->onMouseLeave.connect(std::bind(scaleDownButton, playAgainButton));
    playAgainButton->onClick.connect(std::bind(&Scene::close, this, 1));
    mainButtonsLayout->addChild(playAgainButton);

    auto backToMenuButton = new Button("home-icon.png","",font, 50);
    backToMenuButton->setOutlineThickness(2);
    backToMenuButton->onMouseOver.connect(std::bind(scaleUpButton, backToMenuButton));
    backToMenuButton->onMouseLeave.connect(std::bind(scaleDownButton, backToMenuButton));
    backToMenuButton->onClick.connect(std::bind(&Scene::close, this, 0));
    mainButtonsLayout->addChild(backToMenuButton);
}

///////////////////////////////////////
void GameOverScene::onClose(int scene)
{
	switch (scene)
	{
		case 0: directorAction.type = DirectorAction::ClearPushScene; directorAction.scene = new MainMenu; break;
		case 1: directorAction.type = DirectorAction::PopScene;
	}
}

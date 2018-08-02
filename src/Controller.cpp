#include "Controller.hpp"
#include <LK/Button.hpp>

extern Vector2D windowSize;

///////////////////////////////
Controller::Controller(GameScene *scene) : Player(&scene->getDeck()), selectedCard(nullptr), scene(scene)
{
    scene->connectToEvent(sf::Event::MouseMoved, std::bind(&Controller::onMouseMoved, this, std::placeholders::_1));
    scene->connectToEvent(sf::Event::MouseButtonPressed, std::bind(&Controller::onClick, this, std::placeholders::_1));

    auto moveLayout = [&](bool toLeft) { getChild("cardsLayout")->move(80 * ((toLeft) ? -1 :  1), 0); };

    auto font = AssetsManager::getFont("riffic.otf");
    auto moveToLeftButton = new Button("<", font, 50);
    moveToLeftButton->setColor(Color("#333232"));
    moveToLeftButton->setPosition(- windowSize.x * 0.47f, -70);
    moveToLeftButton->onClick.connect(std::bind(moveLayout, true));
    addChild(moveToLeftButton);

    auto moveToRightButton = new Button(">", font, 50);
    moveToRightButton->setColor(Color("#333232"));
    moveToRightButton->setPosition(windowSize.x * 0.47f, -70);
    moveToRightButton->onClick.connect(std::bind(moveLayout, false));
    addChild(moveToRightButton);
}

///////////////////////////////
void Controller::onMouseMoved(const sf::Event &event)
{
    for (auto *card : getCards())
    {
        if (card->getBoundingBox().contains(event.mouseMove.x, event.mouseMove.y))
        {
            if (card->getPosition().y == 0)
            {
                card->move(0, -5);
                selectedCard = card;
            }
        }
        else if (card->getPosition().y != 0)
        {
            card->move(0, 5);
            selectedCard = nullptr;
        }
    }
}

///////////////////////////////
void Controller::onClick(const sf::Event &event)
{
    if (! selectedCard)
        return;

    if (scene->setCurrentCard(selectedCard->getCard(), this))
    {
        removeCard(selectedCard);
        selectedCard = nullptr;
    }
}

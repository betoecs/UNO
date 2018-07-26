#include "Controller.hpp"

///////////////////////////////
Controller::Controller(GameScene *scene) : Player(&scene->getDeck()), selectedCard(nullptr), scene(scene)
{
    scene->connectToEvent(sf::Event::MouseMoved, std::bind(&Controller::onMouseMoved, this, std::placeholders::_1));
    scene->connectToEvent(sf::Event::MouseButtonPressed, std::bind(&Controller::onClick, this, std::placeholders::_1));
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

#include "Controller.hpp"

///////////////////////////////
Controller::Controller(Scene *scene)
{
    scene->connectToEvent(sf::Event::MouseMoved, std::bind(&Controller::onMouseMoved, this, std::placeholders::_1));
}

///////////////////////////////
void Controller::onMouseMoved(const sf::Event &event)
{
    for (auto *card : getCards())
    {
        if (card->getBoundingBox().contains(event.mouseMove.x, event.mouseMove.y))
        {
            if (card->getPosition().y == 0)
                card->move(0, -5);
        }
        else if (card->getPosition().y != 0)
            card->move(0, 5);
    }
}

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Player.hpp"
#include "GameScene.hpp"
#include "CardEntity.hpp"
#include <SFML/Window/Event.hpp>

using namespace lk;

class Controller : public Player
{
public:
    Controller(GameScene *scene);
    void onClick(const sf::Event &event);
    void onMouseMoved(const sf::Event &event);

private:
    GameScene *scene;
    CardEntity *selectedCard;
};

#endif // CONTROLLER_HPP

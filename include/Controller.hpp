#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Player.hpp"
#include <LK/Scene.hpp>
#include <SFML/Window/Event.hpp>

using namespace lk;

class Controller : public Player
{
public:
    Controller(Scene *scene);
    void onMouseMoved(const sf::Event &event);

private:

};

#endif // CONTROLLER_HPP

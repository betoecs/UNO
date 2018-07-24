#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "Deck.hpp"

#include <LK/Scene.hpp>
using namespace lk;

class GameScene : public Scene
{
public:
	void onCreate() override;
	void onClose(int scene) override;

private:
	Deck deck;
};

#endif // GAME_SCENE_HPP

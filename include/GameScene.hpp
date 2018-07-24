#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include <LK/Scene.hpp>
using namespace lk;

class GameScene : public Scene
{
public:
	void onCreate() override;
	void onClose(int scene) override;
};

#endif // GAME_SCENE_HPP

#ifndef GAME_OVER_SCEHE_HPP
#define GAME_OVER_SCEHE_HPP

#include <LK/Scene.hpp>
using namespace lk;

class GameOverScene : public Scene
{
public:
    GameOverScene (bool winner);
	void onCreate() override;
	void onClose(int scene) override;

private:
    bool winner;
};

#endif // GAME_OVER_SCEHE_HPP

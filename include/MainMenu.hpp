#ifndef MAIN_SCEHE_HPP
#define MAIN_SCEHE_HPP

#include <LK/Scene.hpp>
using namespace lk;

class MainMenu : public Scene
{
public:
	void onCreate() override;
	void onClose(int scene) override;
};

#endif // MAIN_SCEHE_HPP

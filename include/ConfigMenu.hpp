#ifndef CONFIG_SCENE_HPP
#define CONFIG_SCENE_HPP

#include <LK/Scene.hpp>
using namespace lk;

class ConfigMenu : public Scene
{
public:
	void onCreate() override;
	void onClose(int scene) override;
};

#endif // CONFIG_SCENE_HPP

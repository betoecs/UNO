#ifndef FOO_SCENE_HPP
#define FOO_SCENE_HPP

#include <LK/Scene.hpp>
#include <LK/Camera.hpp>
using namespace lk;

class FooScene : public Scene
{
public:
	void onCreate()	override;
	void onClose(int scene) override;
	void onUpdate(float frameTime) override;

private:
	Camera *camera;
};

#endif // FOO_SCENE_HPP

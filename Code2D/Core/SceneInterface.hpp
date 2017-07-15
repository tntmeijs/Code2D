#ifndef SCENE_INTERFACE_HPP
#define SCENE_INTERFACE_HPP

// Every scene should be based on this class!

#include <vector>

#include "../ECS/GameObject.hpp"

namespace Code2D
{
	class SceneInterface
	{
	public:
		virtual void HandleInput() = 0;
		virtual void Update() = 0;

	protected:
		std::vector<GameObject *> GameObjectInScene;
	};
}

#endif
#ifndef RENDERER_2D
#define RENDERER_2D

#include <vector>

#include "glad/glad.h"
#include "Shader.hpp"
#include "../ECS/GameObject.hpp"

namespace Code2D
{
	class Renderer2D
	{
	public:
		void Initialize();
		void SortLayerDepths();

		// Assumes that the game objects have been sorted by layer properly!
		void Render();
		void AddGameObject(GameObject * NewObject);

	private:
		std::vector<GameObject *> RenderableObjects;

		Shader DefaultShader;
	};
}

#endif
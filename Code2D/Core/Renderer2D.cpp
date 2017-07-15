#include "Renderer2D.hpp"
#include "../ECS/Components/Sprite.hpp"

namespace Code2D
{
	void Renderer2D::Initialize()
	{
		DefaultShader.Create(	"./Core/DefaultShaders/vertex.vsh",
								"./Core/DefaultShaders/fragment.fsh");
	}

	void Renderer2D::SortLayerDepths()
	{
	}

	void Renderer2D::Render()
	{
		for (auto Itr : RenderableObjects)
		{
			if (Itr->Components.GetComponent<Component::Sprite>()->PersonalShader != nullptr)
			{
				// We should use the shader this sprite has
				glUseProgram(Itr->Components.GetComponent<Component::Sprite>()->PersonalShader->Get());
			}
			else
			{
				// Use the default shader
				glUseProgram(DefaultShader.Get());
			}

			glBindVertexArray(Itr->Components.GetComponent<Component::Sprite>()->Get());

			// The magic number does not matter, because EVERY sprite will have 6 vertices
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);

			glBindVertexArray(0);
			glUseProgram(0);
		}
	}

	void Renderer2D::AddGameObject(GameObject * NewObject)
	{
		if (NewObject->Components.GetComponent<Component::Sprite>() != nullptr)
		{
			RenderableObjects.push_back(NewObject);
		}
	}
}
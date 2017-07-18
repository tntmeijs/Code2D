#include "Renderer2D.hpp"
#include "../ECS/Components/Sprite.hpp"
#include "../ECS/Components/Transform.hpp"

constexpr GLuint NUM_SPRITE_VERTICES = 6;

namespace Code2D
{
	void Renderer2D::Initialize()
	{
		DefaultShader.Create("./Core/DefaultShaders/vertex.vsh",
			"./Core/DefaultShaders/fragment.fsh");
	}

	void Renderer2D::SortLayerDepths()
	{
	}

	void Renderer2D::Render()
	{
		GLuint ShaderProgramToUse;

		for (auto Itr : RenderableObjects)
		{
			if (Itr->Components.GetComponent<Component::Sprite>()->PersonalShader != nullptr)
			{
				// We should use the shader this sprite has
				ShaderProgramToUse = Itr->Components.GetComponent<Component::Sprite>()->PersonalShader->Get();
			}
			else
			{
				ShaderProgramToUse = DefaultShader.Get();
			}

			glUseProgram(ShaderProgramToUse);

			// This is our sampler2D
			glUniform1i(glGetUniformLocation(ShaderProgramToUse, "u_Texture"), 0);

			// Only using one texture, but activating Texture0 to be safe :)
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, Itr->Components.GetComponent<Component::Sprite>()->SpriteTexture->Get());

			// VAO of the current sprite
			glBindVertexArray(Itr->Components.GetComponent<Component::Sprite>()->Get());
			glDrawElements(GL_TRIANGLES, NUM_SPRITE_VERTICES, GL_UNSIGNED_SHORT, nullptr);

			glBindVertexArray(0);
			glBindTexture(GL_TEXTURE_2D, 0);
			glUseProgram(0);
		}
	}

	void Renderer2D::AddGameObject(GameObject * NewObject)
	{
		// We need to have a transform and a sprite when rendering!
		if (NewObject->Components.GetComponent<Component::Sprite>() != nullptr &&
			NewObject->Components.GetComponent<Component::Transform>() != nullptr)
		{
			RenderableObjects.push_back(NewObject);
		}
	}
}
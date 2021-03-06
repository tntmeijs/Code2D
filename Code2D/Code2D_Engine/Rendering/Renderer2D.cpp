#include "Renderer2D.hpp"
#include "glm/mat4x4.hpp"
#include "../ECS/Components/Sprite.hpp"

constexpr GLuint NUM_SPRITE_VERTICES = 6;

namespace Code2D
{
	void Renderer2D::Initialize()
	{
		DefaultShader.Create(	"./Code2D_Engine/Rendering/DefaultShaders/vertex.vsh",
								"./Code2D_Engine/Rendering/DefaultShaders/fragment.fsh");
	}

	void Renderer2D::SortLayerDepths()
	{
	}

	void Renderer2D::Render(Camera2D * CameraToRenderWith)
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

			glm::mat4 MVP = CameraToRenderWith->CalculateAndGetProjectionViewMatrix() * Itr->Transform.CalculateAndGetModelMatrix();
			glUniformMatrix4fv(glGetUniformLocation(ShaderProgramToUse, "u_MVP"), 1, GL_FALSE, &MVP[0][0]);

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
		// We need to have a sprite when rendering!
		if (NewObject->Components.GetComponent<Component::Sprite>() != nullptr)
		{
			RenderableObjects.push_back(NewObject);
		}
	}
}
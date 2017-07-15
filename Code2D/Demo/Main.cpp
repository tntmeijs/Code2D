#include "../Core/Window.hpp"
#include "../Core/Shader.hpp"
#include "../ECS/GameObject.hpp"
#include "../ECS/Components/Sprite.hpp"

int main(int argc, char * args[])
{
	Code2D::Window Window;
	Window.Create();

	Code2D::Shader TestShader;
	TestShader.Create(	"./Demo/Assets/Shaders/vertex.vsh",
						"./Demo/Assets/Shaders/fragment.fsh");

	Code2D::GameObject DemoObject;
	DemoObject.Components.AddComponent(new Code2D::Component::Sprite);

	Code2D::Component::Sprite * Sprite = DemoObject.Components.GetComponent<Code2D::Component::Sprite>();

	Sprite->Create();

	while (Window.GameShouldRun())
	{
		Window.ProcessInput();
		Window.PrepareFrame();

		// update
		
		// render
		glUseProgram(TestShader.Get());
		glBindVertexArray(Sprite->Get());
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);
		glBindVertexArray(0);
		glUseProgram(0);

		Window.ShowFrame();
	}

	return 0;
}
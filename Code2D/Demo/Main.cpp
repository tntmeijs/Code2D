#include "../Core/Window.hpp"
#include "../Core/Renderer2D.hpp"
#include "../Core/Camera2D.hpp"
#include "../ECS/GameObject.hpp"
#include "../ECS/Components/Sprite.hpp"
#include "../ECS/Components/Transform.hpp"

int main(int argc, char * args[])
{
	Code2D::Window Window;
	Window.Create();

	Code2D::Renderer2D Renderer;
	Renderer.Initialize();

	Code2D::Camera2D MainCamera;
	MainCamera.Create(12.8f, 7.2f); // I have chosen a 100x lower resolution, because sprites are 1x1 pixels right now

	Code2D::GameObject * DemoObject = new Code2D::GameObject;
	DemoObject->Components.AddComponent(new Code2D::Component::Sprite);
	DemoObject->Components.AddComponent(new Code2D::Component::Transform);

	Code2D::Component::Sprite * Sprite = DemoObject->Components.GetComponent<Code2D::Component::Sprite>();

	Sprite->Create("./Demo/Assets/Sprites/sprite_01.png");
	
	Renderer.AddGameObject(DemoObject);

	while (Window.GameShouldRun())
	{
		Window.ProcessInput();
		Window.PrepareFrame();

		// update

		// render
		Renderer.Render(&MainCamera);

		Window.ShowFrame();
	}

	delete DemoObject;

	return 0;
}
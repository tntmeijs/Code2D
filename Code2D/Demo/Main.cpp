#include "../Core/Window.hpp"
#include "../Core/Renderer2D.hpp"
#include "../Core/Camera2D.hpp"
#include "../Core/Input.hpp"
#include "../ECS/GameObject.hpp"
#include "../ECS/Components/Sprite.hpp"
#include "../ECS/Components/Transform.hpp"

#include <cmath>

int main(int argc, char * args[])
{
	Code2D::Window Window;
	Window.Create();

	Code2D::Renderer2D Renderer;
	Renderer.Initialize();

	Code2D::Camera2D MainCamera;
	MainCamera.Create();

	Code2D::GameObject * DemoObject = new Code2D::GameObject;
	DemoObject->Components.AddComponent(new Code2D::Component::Sprite);
	DemoObject->Components.AddComponent(new Code2D::Component::Transform);

	Code2D::Component::Sprite * Sprite = DemoObject->Components.GetComponent<Code2D::Component::Sprite>();
	Code2D::Component::Transform * Transform = DemoObject->Components.GetComponent<Code2D::Component::Transform>();

	Sprite->Create("./Demo/Assets/Sprites/sprite_01.png");

	float i = 0.0f;

	Renderer.AddGameObject(DemoObject);

	// Bind a key to a name (makes dynamic key mapping easier)
	Code2D::Input::BindKey("testkey", Code2D::Input::KEY::G);

	while (Window.GameShouldRun())
	{
		Window.QueryInput();
		// Input class demonstration
		if (Code2D::Input::KeyPressed("testkey"))
		{
			i += 0.05f;
			std::printf("PRESSED");
		}
		else
		{
			std::printf("RELEASED");
		}

		Window.PrepareFrame();

		// Transform component demonstration
		Transform->SetPosition(640.0f, 360.0f);
		Transform->RotationZ = std::sin(i) * 40.0f;
		Transform->Scale.x = 1.25f;

		// Sprite component rendering demonstration
		Renderer.Render(&MainCamera);

		Window.ShowFrame();
	}

	delete DemoObject;

	return 0;
}
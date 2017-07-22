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
	// Create a window
	Code2D::Window Window;
	Window.Create();

	// Setup the renderer
	Code2D::Renderer2D Renderer;
	Renderer.Initialize();

	// Add a camera
	Code2D::Camera2D MainCamera;
	MainCamera.Create();

	// Instantiate a game object with a couple of components
	Code2D::GameObject * DemoObject = new Code2D::GameObject;
	DemoObject->Components.AddComponent(new Code2D::Component::Sprite);
	DemoObject->Components.AddComponent(new Code2D::Component::Transform);

	// Show the retrieval of components from a game object
	Code2D::Component::Sprite * Sprite = DemoObject->Components.GetComponent<Code2D::Component::Sprite>();
	Code2D::Component::Transform * Transform = DemoObject->Components.GetComponent<Code2D::Component::Transform>();

	Sprite->Create("./Demo/Assets/Sprites/sprite_01.png");

	float i = 0.0f;

	Renderer.AddGameObject(DemoObject);

	// Bind a key to a name (makes dynamic key mapping easier)
	Code2D::Input::BindKey("increment", Code2D::Input::KEY::UP);
	Code2D::Input::BindKey("decrement", Code2D::Input::KEY::DOWN);

	while (Window.GameShouldRun())
	{
		Window.QueryInput();
		// Input class demonstration (press the 'up' arrow to increment, and the 'down' arrow to decrement)
		if (Code2D::Input::KeyPressed("increment"))
		{
			i += 0.01f;
		}

		if (Code2D::Input::KeyPressed("decrement"))
		{
			i -= 0.01f;
		}

		// Makes a call to the glClear function
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

	// Cleanup after ourselves
	Code2D::Input::Stop();
	Window.Stop();

	return 0;
}
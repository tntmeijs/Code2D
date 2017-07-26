#include "../Code2D_Engine/Misc/Window.hpp"
#include "../Code2D_Engine/Rendering/Renderer2D.hpp"
#include "../Code2D_Engine/Rendering/Camera2D.hpp"
#include "../Code2D_Engine/Misc/Input.hpp"
#include "../Code2D_Engine/ECS/GameObject.hpp"
#include "../Code2D_Engine/ECS/Components/Sprite.hpp"

#include "../Code2D_Engine/Physics/AABB.hpp"

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
	Code2D::GameObject * DemoObject1 = new Code2D::GameObject;
	DemoObject1->Components.AddComponent(new Code2D::Component::Sprite);

	Code2D::GameObject * DemoObject2 = new Code2D::GameObject;
	DemoObject2->Components.AddComponent(new Code2D::Component::Sprite);

	// Show the retrieval of components from a game object
	Code2D::Component::Sprite * Sprite1 = DemoObject1->Components.GetComponent<Code2D::Component::Sprite>();

	Code2D::Component::Sprite * Sprite2 = DemoObject2->Components.GetComponent<Code2D::Component::Sprite>();

	Sprite1->Create("./Demo/Assets/Sprites/sprite_01.png");
	Sprite2->Create("./Demo/Assets/Sprites/sprite_02.png");

	DemoObject1->Transform.SetPosition(280.0f, 360.0f);
	DemoObject1->Transform.Size.x = 50.0f;
	DemoObject1->Transform.Size.y = 50.0f;

	DemoObject2->Transform.SetPosition(1000.0f, 360.0f);

	// Player one controls
	Code2D::Input::BindKey("GO_1_UP", Code2D::Input::W);
	Code2D::Input::BindKey("GO_1_DOWN", Code2D::Input::S);
	Code2D::Input::BindKey("GO_1_LEFT", Code2D::Input::A);
	Code2D::Input::BindKey("GO_1_RIGHT", Code2D::Input::D);
	Code2D::Input::BindKey("GO_1_ROTATE_L", Code2D::Input::Q);
	Code2D::Input::BindKey("GO_1_ROTATE_R", Code2D::Input::E);
	
	// Game objects we would like to render:
	Renderer.AddGameObject(DemoObject1);
	Renderer.AddGameObject(DemoObject2);

	while (Window.GameShouldRun())
	{
		// Fancy way of saying 'glfwPollEvents()'
		Window.QueryInput();

		// Game object 1 input handling
		if (Code2D::Input::KeyPressed("GO_1_UP")) { DemoObject1->Transform.Position.y -= 3.0f; };
		if (Code2D::Input::KeyPressed("GO_1_DOWN")) { DemoObject1->Transform.Position.y += 3.0f; };
		if (Code2D::Input::KeyPressed("GO_1_LEFT")) { DemoObject1->Transform.Position.x -= 3.0f; };
		if (Code2D::Input::KeyPressed("GO_1_RIGHT")) { DemoObject1->Transform.Position.x += 3.0f; };
		if (Code2D::Input::KeyPressed("GO_1_ROTATE_L")) { DemoObject1->Transform.RotationZ += 2.0f; };
		if (Code2D::Input::KeyPressed("GO_1_ROTATE_R")) { DemoObject1->Transform.RotationZ -= 2.0f; };

		// Makes a call to the 'glClear()' function
		Window.PrepareFrame();

		// update
		std::printf("Collision happening: %i\n", Code2D::Physics::AABB::GameObjectsIntersect(*DemoObject1, *DemoObject2));

		// Sprite component rendering demonstration
		Renderer.Render(&MainCamera);

		Window.ShowFrame();
	}

	delete DemoObject1;
	delete DemoObject2;

	// Cleanup after ourselves
	Code2D::Input::Stop();
	Window.Stop();

	return 0;
}
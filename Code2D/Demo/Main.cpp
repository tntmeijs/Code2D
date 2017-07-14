#include "../Core/Window.hpp"

int main(int argc, char * args[])
{
	Code2D::Window Window;
	Window.Create();

	while (Window.GameShouldRun())
	{
		Window.ProcessInput();
		Window.PrepareFrame();

		// update

		Window.ShowFrame();
	}

	return 0;
}
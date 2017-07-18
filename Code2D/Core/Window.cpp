#include "Window.hpp"
#include "Input.hpp"
#include <iostream>

namespace Code2D
{
	Window::Window()
	{
	}

	Window::~Window()
	{
		glfwDestroyWindow(GameWindow);
		glfwTerminate();
	}

	void Window::Create(bool bFullscreen, short WindowWidth, short WindowHeight, const char * Title)
	{
		this->WindowWidth = WindowWidth;
		this->WindowHeight = WindowHeight;
		this->bFullscreen = bFullscreen;
		this->Title = Title;

		glfwSetErrorCallback(ErrorCallback);

		// GLFW3 Initialization
		if (!glfwInit())
		{
			return;
		}

		SetWindowHints();

		Monitor = glfwGetPrimaryMonitor();
		Videomode = glfwGetVideoMode(Monitor);

		// Calculate the position to place the window at the center of the screen
		float x = (Videomode->width * 0.5f) - (WindowWidth * 0.5f);
		float y = (Videomode->height * 0.5f) - (WindowHeight * 0.5f);

		// TODO: enable toggling full screen
		// Create a window
		GameWindow = glfwCreateWindow(WindowWidth, WindowHeight, Title, nullptr, nullptr);
		glfwSetWindowPos(GameWindow, static_cast<int>(x), static_cast<int>(y));

		if (GameWindow == nullptr)
		{
			glfwTerminate();
			return;
		}

		// Make the window the current active context
		glfwMakeContextCurrent(GameWindow);

		// TODO: add callbacks
		// Callback functions
		glfwSetKeyCallback(GameWindow, Input::KeyCallback);

		// Load GLAD
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		// OpenGL parameters
		int Width, Height;
		glfwGetFramebufferSize(GameWindow, &Width, &Height);
		glViewport(0, 0, Width, Height);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	bool Window::GameShouldRun() const
	{
		return !glfwWindowShouldClose(GameWindow);
	}

	void Window::ProcessInput() const
	{
		glfwPollEvents();
	}

	void Window::PrepareFrame() const
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::ShowFrame() const
	{
		glfwSwapBuffers(GameWindow);
	}

	void Window::ErrorCallback(int Error, const char * Description)
	{
		// Just log the errors to the console for now...
		std::printf("Whoops, GLFW encountered an error!\n%s", Description);
	}

	void Window::SetWindowHints()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		glfwWindowHint(GLFW_DECORATED, GL_FALSE);
	}
}
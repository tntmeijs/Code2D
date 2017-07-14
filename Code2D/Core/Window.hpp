#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Code2D
{
	class Window
	{
	public:
		Window();
		~Window();

		void Create(bool bFullscreen = false,
					short WindowWidth = 1280,
					short WindowHeight = 720,
					const char * Title = "Powered by Code2D!");
		bool GameShouldRun() const;
		void ProcessInput() const;
		void PrepareFrame() const;
		void ShowFrame() const;

	private:
		static void ErrorCallback(int Error, const char * Description);

		void SetWindowHints();

		short WindowWidth;
		short WindowHeight;

		bool bFullscreen;

		const char * Title;

		const GLFWvidmode * Videomode;
		GLFWmonitor * Monitor;
		GLFWwindow * GameWindow;
	};
}

#endif
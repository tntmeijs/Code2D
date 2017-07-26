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

		void Create(int WindowWidth = 1280,
					int WindowHeight = 720,
					const char * Title = "Powered by Code2D!",
					bool bFullscreen = false);
		bool GameShouldRun() const;
		void QueryInput() const;
		void PrepareFrame() const;
		void ShowFrame() const;

		// Toggle between a normal cursor, and a hidden cursor (does not disable the cursor!)
		void SetCursorVisibility(bool Visible);

		void Stop();

	private:
		static void ErrorCallback(int Error, const char * Description);

		void SetWindowHints();

		int WindowWidth;
		int WindowHeight;

		bool bFullscreen;

		const char * Title;

		const GLFWvidmode * Videomode;
		GLFWmonitor * Monitor;
		GLFWwindow * GameWindow;
	};
}

#endif
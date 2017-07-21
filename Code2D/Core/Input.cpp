#include "Input.hpp"

std::map<const char *, int> Code2D::Input::KeyBindings;

int Code2D::Input::KeyFromCallback;
int Code2D::Input::ScancodeFromCallback;
int Code2D::Input::ActionFromCallback;
int Code2D::Input::ModsFromCallback;

namespace Code2D
{
	void Input::KeyCallback(GLFWwindow * Window, int Key, int Scancode, int Action, int Mods)
	{
		KeyFromCallback = Key;
		ScancodeFromCallback = Scancode;
		ActionFromCallback = Action;
		ModsFromCallback = Mods;
	}

	void Input::BindKey(const char * Name, int Key)
	{
		KeyBindings[Name] = Key;
	}

	bool Input::KeyPressed(const char * name)
	{
		if (GetKeyByName(name) == KeyFromCallback &&
			ActionFromCallback == GLFW_PRESS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Input::KeyReleased(const char * name)
	{
		if (GetKeyByName(name) == KeyFromCallback &&
			ActionFromCallback == GLFW_RELEASE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Input::GetKeyByName(const char * name)
	{
		auto Itr = KeyBindings.find(name);

		if (Itr != KeyBindings.end())
		{
			// Found the requested entry!
			return Itr->second;
		}
		else
		{
			return -1;
		}
	}
}
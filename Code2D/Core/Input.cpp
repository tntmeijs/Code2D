#include "Input.hpp"

std::map<const char *, Code2D::Input::KeyData *> Code2D::Input::KeyBindings;

namespace Code2D
{
	void Input::KeyCallback(GLFWwindow * Window, int Key, int Scancode, int Action, int Mods)
	{
		// Check if the key that is being pressed is a keybinding in the engine
		if (Action == GLFW_PRESS)
		{
			// If so, set the key state to true (pressed)
			for (auto Itr : KeyBindings)
			{
				if (Itr.second->Key == Key)
				{
					Itr.second->State = true;
				}
			}
		}
		
		if (Action == GLFW_RELEASE)
		{
			// Else, set the key state to false (released)
			for (auto Itr : KeyBindings)
			{
				if (Itr.second->Key == Key)
				{
					Itr.second->State = false;
				}
			}
		}
	}

	void Input::BindKey(const char * Name, int Key, bool DefaultState)
	{
		for (auto Itr : KeyBindings)
		{
			if (Itr.second->Key == Key)
			{
				if (Itr.first == Name)
				{
					// Name and key are already in the map (trying to add a duplicate)!
					std::printf("Whoops, '%s' already exists as a keybind, are you are tying to add a duplicate?\n", Name);
					return;
				}

				// This key already exists in the map!
				std::printf("Whoops, the key already exists as a keybinding to the name '%s'!\n", Itr.first);
				return;
			}
		}

		// Add the new keybinding to the map (overwrites any existing entries)
		KeyBindings[Name] = new KeyData(Key, DefaultState);
	}

	bool Input::KeyPressed(const char * Name)
	{
		return GetKeyStateByName(Name);
	}

	bool Input::KeyReleased(const char * Name)
	{
		return !GetKeyStateByName(Name);
	}

	void Input::Stop()
	{
		// Loop through all key bindings and delete the pointers
		for (auto Itr : KeyBindings)
		{
			delete Itr.second;
		}

		KeyBindings.clear();
	}

	bool Input::GetKeyStateByName(const char * Name)
	{
		auto Itr = KeyBindings.find(Name);

		if (Itr != KeyBindings.end())
		{
			// Found the entry!
			return Itr->second->State;
		}

		// Could not find the key!
		std::printf("Whoops, the key name '%s' does not seem to exist!\n", Name);
		return false;
	}
}
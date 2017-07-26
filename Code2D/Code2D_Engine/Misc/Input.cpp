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
			// Check if the key is a duplicate
			if (Itr.first == Name && Itr.second->Key == Key)
			{
				std::printf("'%s' Already exists as a key binding!\nYou seem to be trying to add a duplicate entry...\n", Itr.first);
				return;
			}

			if (Itr.first == Name)
			{
				// name exists already, should replace the key
				KeyBindings[Name]->Key = Key;
				return;
			}

			if (Itr.second->Key == Key)
			{
				// Key exists already, so we assume the user wants to overwrite the previous entry
				std::printf("This key is already bound to '%s'!\nOverwriting '%s' with '%s'...\n", Itr.first, Itr.first, Name);
				
				// Erase the current entry (map keys are immutable)
				delete Itr.second;
				KeyBindings.erase(Itr.first);

				// Insert the new pair
				KeyBindings[Name] = new KeyData(Key, DefaultState);

				return;
			}

			auto ItrResult = KeyBindings.find(Name);
			if (ItrResult == KeyBindings.end())
			{
				// Entry does not exist yet, so add it to the map
				KeyBindings[Name] = new KeyData(Key, DefaultState);
				return;
			}
		}


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
		std::printf("Whoops, the key name '%s' does not seem to exist (anymore)!\n", Name);
		return false;
	}
}
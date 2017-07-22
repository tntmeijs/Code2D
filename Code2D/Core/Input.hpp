#ifndef INPUT_HPP
#define INPUT_HPP

#include "GLFW/glfw3.h"

#include <map>

namespace Code2D
{
	class Input
	{
	public:
		// Gets called from the GLFW callback in the Window class
		static void KeyCallback(GLFWwindow * Window, int Key, int Scancode, int Action, int Mods);
		static void BindKey(const char * Name, int Key, bool DefaultState = false);
		static bool KeyPressed(const char * Name);
		static bool KeyReleased(const char * Name);

		// Makes sure to delete all pointers in the map
		static void Stop();

		// All keys from the GLFW3 header
		// Keys are copied from the GLFW header
		enum KEY
		{
			UNKNOWN = -1,

			SPACE = 32,

			APOSTROPHE = 39,

			COMMA = 44,
			MINUS,
			PERIOD,
			SLASH,
			ZERO,
			ONE,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
			SEVEN,
			EIGHT,
			NINE,

			SEMICOLON = 59,

			EQUAL = 61,

			A = 65,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			LEFT_BRACKET,
			BACKSLASH,
			RIGHT_BRACKET,

			ACCENT_GRAVE = 96,

			WORLD_1 = 161,
			WORLD_2,

			ESCAPE = 256,
			ENTER,
			TAB,
			BACKSPACE,
			INSERT,
			DEL,
			RIGHT,
			LEFT,
			DOWN,
			UP,
			PAGE_UP,
			PAGE_DOWN,
			HOME,
			END,

			CAPS_LOCK = 280,
			SCROLL_LOCK,
			NUM_LOCK,
			PRINT_SCREEN,
			PAUSE,

			F1 = 290,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,
			F13,
			F14,
			F15,
			F16,
			F17,
			F18,
			F19,
			F20,
			F21,
			F22,
			F23,
			F24,
			F25,

			KEYPAD_ZERO = 320,
			KEYPAD_ONE,
			KEYPAD_TWO,
			KEYPAD_THREE,
			KEYPAD_FOUR,
			KEYPAD_FIVE,
			KEYPAD_SIX,
			KEYPAD_SEVEN,
			KEYPAD_EIGHT,
			KEYPAD_NINE,
			KEYPAD_DECIMAL,
			KEYPAD_DIVIDE,
			KEYPAD_MULTIPLY,
			KEYPAD_SUBTRACT,
			KEYPAD_ADD,
			KEYPAD_ENTER,
			KEYPAD_EQUAL,

			LEFT_SHIFT = 340,
			LEFT_CTRL,
			LEFT_ALT,
			LEFT_SUPER,
			RIGHT_SHIFT,
			RIGHT_CTRL,
			RIGHT_ALT,
			RIGHT_SUPER,
			MENU
		};

	private:
		struct KeyData
		{
			KeyData(int Key, bool State)
			{
				this->Key = Key;
				this->State = State;
			}

			int Key;
			bool State;
		};

		static bool GetKeyStateByName(const char * Name);

		static std::map<const char *, KeyData *> KeyBindings;
	};
}

#endif
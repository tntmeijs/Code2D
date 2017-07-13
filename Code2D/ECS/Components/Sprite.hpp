/*
This class is a sprite component
It handles all the buffer creation for OpenGL, as well as
storing the texture associated with this component.

I could have made more specialized components, but it felt
as if it would make using the engine much more complicated.
*/

// TODO: instanced rendering!

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../ComponentInterface.hpp"

///#include "glad/glad.h"

namespace Code2D
{
	namespace Component
	{
		class Sprite : public ComponentInterface
		{
		public:
			void Update();

		private:
			// OpenGL buffers
			///GLuint VAO, VBO, EBO;
		};
	}
}

#endif
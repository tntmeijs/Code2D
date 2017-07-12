/*
This component handles everything regarding transforms
Even though almost every object will have this component,
there might be cases in which it is not needed (e.g. managers)
*/

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "../ComponentInterface.hpp"

namespace Code2D
{
	namespace ComponentType
	{
		class Transform : public ComponentInterface
		{
		public:

		private:
		};
	}
}

#endif
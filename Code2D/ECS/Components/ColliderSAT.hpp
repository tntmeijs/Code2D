#ifndef COLLIDER_SAT_HPP
#define COLLIDER_SAT_HPP

#include "../GameObject.hpp"
#include "../ComponentInterface.hpp"

/*
Only for BOXES for the time being...
Might add some more features later on, like custom polygons for collision detection
*/

namespace Code2D
{
	namespace Component
	{
		class ColliderSAT : public ComponentInterface
		{
		public:
			ColliderSAT(GameObject::TransformData * TransformToUse);

		private:
		};
	}
}

#endif // !COLLIDER_SAT_HPP

#ifndef AABB_HPP
#define AABB_HPP

// Static class which returns all info needed to resolve simple AABB collisions

#include "../ECS/GameObject.hpp"

namespace Code2D
{
	namespace Physics
	{
		class AABB
		{
		public:
			static bool GameObjectsIntersect(const GameObject & ObjectOne, const GameObject & ObjectTwo);

		private:
		};
	}
}

#endif // !AABB_HPP

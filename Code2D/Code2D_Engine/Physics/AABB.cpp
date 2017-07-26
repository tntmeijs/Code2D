#include "AABB.hpp"

namespace Code2D
{
	namespace Physics
	{
		bool AABB::GameObjectsIntersect(const GameObject & ObjectOne, const GameObject & ObjectTwo)
		{
			return(
				ObjectOne.Transform.Position.x - (ObjectOne.Transform.Size.x / 2.0f) < ObjectTwo.Transform.Position.x + (ObjectTwo.Transform.Size.x / 2.0f) &&
				ObjectOne.Transform.Position.x + (ObjectOne.Transform.Size.x / 2.0f) > ObjectTwo.Transform.Position.x - (ObjectTwo.Transform.Size.x / 2.0f) &&

				ObjectOne.Transform.Position.y - (ObjectOne.Transform.Size.y / 2.0f) < ObjectTwo.Transform.Position.y + (ObjectTwo.Transform.Size.y / 2.0f) &&
				ObjectOne.Transform.Position.y + (ObjectOne.Transform.Size.y / 2.0f) > ObjectTwo.Transform.Position.y - (ObjectTwo.Transform.Size.y / 2.0f)
				);
		}
	}
}
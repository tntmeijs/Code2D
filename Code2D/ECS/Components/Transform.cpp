#include "Transform.hpp"
#include "glm/glm.hpp"

namespace Code2D
{
	namespace Component
	{
		Transform::Transform()
		{
			Position.x = 0.0f;
			Position.y = 0.0f;

			Size.x = 100.0f;
			Size.y = 100.0f;

			RotationZ = 0.0f;
		}

		void Transform::SetPosition(float x, float y)
		{
			Position.x = x;
			Position.y = y;
		}
	}
}
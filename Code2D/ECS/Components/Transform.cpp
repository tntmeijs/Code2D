#include "Transform.hpp"

#include <iostream>

namespace Code2D
{
	namespace Component
	{
		Transform::Transform()
		{
			std::cout << "Transform component created!" << std::endl;

			Position.x = 0.0f;
			Position.y = 0.0f;

			Size.x = 100.0f;
			Size.y = 100.0f;
		}

		Transform::~Transform()
		{
			std::cout << "Transform component deleted!" << std::endl;
		}

		void Transform::SetPosition(float x, float y)
		{
			Position.x = x;
			Position.y = y;
		}
	}
}
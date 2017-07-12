#include "../ECS/GameObject.hpp"
#include "../ECS/Components/Transform.hpp"

#include <iostream>

int main(int argc, char * args[])
{
	Code2D::GameObject GameObject;
	GameObject.Components.AddComponent(new Code2D::Component::Transform);

	std::cin.get();

	Code2D::Component::Transform* t = GameObject.Components.GetComponent<Code2D::Component::Transform>();
	
	std::cout << "Transform position: ";
	std::cout << t->Position.x << " " << t->Position.y << std::endl;

	std::cin.get();
	std::cin.get();

	t->Position.x = 5.0f;
	t->Position.y = 7.0f;

	std::cout << "Transform position: ";
	std::cout << t->Position.x << " " << t->Position.y << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

/// QUICK TEST OF A SIMPLE ECS

namespace Component
{
	class ComponentInterface
	{
	public:
		// Virtual destructor to enable us to delete derived classes without undefined behavior
		virtual ~ComponentInterface() {}

		void SayHello()
		{
			std::cout << typeid(*this).name() << " reporting!" << std::endl;
		}
	};

	class Transform : public ComponentInterface
	{
	public:
		Transform()
		{
			std::cout << "Transform Created!" << std::endl;
		}

		~Transform()
		{
			std::cout << typeid(*this).name() << " deleted!" << std::endl;
		}
	};

	class Sprite2D : public ComponentInterface
	{
	public:
		Sprite2D()
		{
			std::cout << "Sprite2D Created!" << std::endl;
		}

		~Sprite2D()
		{
			std::cout << typeid(*this).name() << " deleted!" << std::endl;
		}
	};

	class Animation2D : public ComponentInterface
	{
	public:
		Animation2D()
		{
			std::cout << "Animation2D Created!" << std::endl;
		}

		~Animation2D()
		{
			std::cout << typeid(*this).name() << " deleted!" << std::endl;
		}
	};
}

class GameObject
{
public:
	// Adds a new component to the game object
	void AddComponent(Component::ComponentInterface* NewComponent)
	{
		std::cout << typeid(*NewComponent).name() << " added to the game object!" << std::endl;

		Components[&typeid(*NewComponent)] = NewComponent;
	}

	// Retrieves a specific component, or nullptr if there is no such component found
	template<typename T>
	T* GetComponent()
	{
		if (Components.count(&typeid(T)) != 0)
		{
			// Component found!
			return static_cast<T*>(Components[&typeid(T)]);
		}
		else
		{
			return nullptr;
		}
	}

	template<typename T>
	bool RemoveComponent()
	{
		if (Components.count(&typeid(T)) != 0)
		{
			delete static_cast<T*>(Components[&typeid(T)]);

			return true;
		}
		else
		{
			return false;
		}
	}

private:
	std::unordered_map<const type_info*, Component::ComponentInterface*> Components;
};

int main(int argc, char * args[])
{
	GameObject FirstObject;
	
	std::cin.get();

	// Add a component
	FirstObject.AddComponent(new Component::Transform);

	std::cin.get();
	std::cin.get();

	// Get the requested component (nullptr if not found)
	FirstObject.GetComponent<Component::Transform>()->SayHello();

	std::cin.get();
	std::cin.get();

	std::cout << FirstObject.RemoveComponent<Component::Transform>() << std::endl;

	std::cin.get();
	std::cin.get();

	// Add all other components
	FirstObject.AddComponent(new Component::Sprite2D);
	FirstObject.AddComponent(new Component::Animation2D);

	std::cin.get();
	std::cin.get();

	// Get some components to check if they actually work
	FirstObject.GetComponent<Component::Sprite2D>()->SayHello();
	FirstObject.GetComponent<Component::Animation2D>()->SayHello();

	std::cin.get();
	std::cin.get();

	std::cout << FirstObject.RemoveComponent<Component::Sprite2D>() << std::endl;
	std::cout << FirstObject.RemoveComponent<Component::Animation2D>() << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}
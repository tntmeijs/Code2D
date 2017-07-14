/*
This class is meant to be a manager for all components of a game object
Each game object needs to have this class to make use of the ECS
*/

#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <unordered_map>
#include <typeinfo>

#include "ComponentInterface.hpp"

namespace Code2D
{
	class Components
	{
	public:
		// Clean up after ourselves
		~Components();

		// Add a new component: GameObject.AddComponent(new [TYPE]);
		void AddComponent(Component::ComponentInterface * NewComponent);

		// Get the requested component, or 'nullptr' if the component is not available: GameObject.GetComponent<[TYPE]>();
		template<typename T>
		T* GetComponent();

	private:
		std::unordered_map<const std::type_info *, Component::ComponentInterface *> ComponentMap;
	};

	template<typename T>
	inline T * Components::GetComponent()
	{
		if (ComponentMap.count(&typeid(T)) != 0)
		{
			// Component exists!
			return static_cast<T*>(ComponentMap[&typeid(T)]);
		}
		else
		{
			// Could not find the requested components
			return nullptr;
		}
	}
}

#endif
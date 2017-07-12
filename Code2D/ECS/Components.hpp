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
		void AddComponent(ComponentType::ComponentInterface* NewComponent);

		// Get the requested component, or 'nullptr' if the component is not available: GameObject.GetComponent<[TYPE]>();
		template<typename T>
		T* GetComponent();

		// Remove a component: GameObject.RemoveComponent<[TYPE]>();
		template<typename T>
		bool RemoveComponent();

	private:
		std::unordered_map<const std::type_info*, ComponentType::ComponentInterface*> ComponentMap;
	};
}

#endif
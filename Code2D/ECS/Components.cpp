#include "Components.hpp"

namespace Code2D
{
	Components::~Components()
	{
		for (auto Itr : ComponentMap)
		{
			// Delete the object
			delete Itr.second;

			// Delete the pointer to the type
			delete Itr.first;
		}

		ComponentMap.clear();
	}

	void Components::AddComponent(ComponentType::ComponentInterface* NewComponent)
	{
		ComponentMap[&typeid(*NewComponent)] = NewComponent;
	}

	template<typename T>
	inline T * Components::GetComponent()
	{
		if (ComponentMap.count(&typeid(T)) != 0)
		{
			// Component exists!
			return static_cast<T*>(Components[&typeid(T)]);
		}
		else
		{
			// Could not find the requested components
			return nullptr;
		}
	}

	template<typename T>
	bool Components::RemoveComponent()
	{
		if (ComponentMap.count(&typeid(T)) != 0)
		{
			// Component exists, so we can delete it!
			delete static_cast<T*>(Components[&typeid(T)]);

			return true;
		}
		else
		{
			return false;
		}
	}
}
#include "Components.hpp"

namespace Code2D
{
	Components::~Components()
	{
		for (auto Itr : ComponentMap)
		{
			// Delete the component
			delete Itr.second;
		}

		ComponentMap.clear();
	}

	void Components::AddComponent(Component::ComponentInterface* NewComponent)
	{
		ComponentMap[&typeid(*NewComponent)] = NewComponent;
	}
}
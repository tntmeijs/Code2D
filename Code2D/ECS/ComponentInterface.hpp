#ifndef COMPONENT_INTERFACE_HPP
#define COMPONENT_INTERFACE_HPP

namespace Code2D
{
	namespace ComponentType
	{
		class ComponentInterface
		{
		public:
			virtual ~ComponentInterface() {}

			virtual void Update() {}
		};
	}
}

#endif
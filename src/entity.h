#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <vector>
#include <string>
#include <typeinfo>

#include "component.h"
#include "entity_manager.h"

namespace Radix
{
	class EntityManager;

	class Entity
	{
		private:
			bool active;
			EntityManager* entity_manager;
			std::vector<Component*> components;
			std::map<const std::type_info*, Component*> component_map;

		public:
			std::string name;
			unsigned int render_layer;

			Entity(EntityManager*);

			Entity(EntityManager*, std::string, unsigned int);

			void update(float);

			void render();

			void destroy();

			bool is_active();

			template<typename T, typename... T_ARGS>
				T* add_component(T_ARGS&&... args)
				{
					T* component(new T(std::forward<T_ARGS>(args)...));
					component->entity = this;
					components.emplace_back(component);
					component_map[&typeid(*component)] = component;
					component->initialize();
					return component;
				}

			template<typename T>
				T* get_component()
				{
					return static_cast<T*>(component_map[&typeid(T)]);
				}

			template<typename T>
				bool has_component()
				{
					return component_map.count(&typeid(T));
				}
	};
}

#endif
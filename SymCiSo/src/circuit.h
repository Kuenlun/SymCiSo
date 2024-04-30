#pragma once

#include <vector>
#include <memory>
#include <string>

#include "core/core.h"
#include "core/log.h"
#include "node.h"

namespace SymCiSo
{

	class Circuit
	{
	public:
		Circuit();
		~Circuit();

		inline const std::vector<std::shared_ptr<Component>>& get_components() const { return m_components; }
		inline size_t get_num_components() const { return m_components.size(); }
		size_t get_num_nodes() const;
		inline std::vector<Node*>& get_nodes() { return m_nodes; }

		template<typename T, typename... Args>
		std::shared_ptr<T> add_component(const Args&... args)
		{
			// Create a shared ptr to the new component (Resistor, Capacitor, ...)
			std::shared_ptr<T> component = std::make_shared<T>(*this, args...);
			// Add the component to the circuit list of components
			m_components.emplace_back(component);
			SYMCISO_CORE_INFO("Added {} {}", component->get_class_name(), *component);
			return component;
		}

		void print() const;

	private:
		std::vector<Node*> m_nodes;
		std::vector<std::shared_ptr<Component>> m_components;
	};

} // namespace SymCiSo
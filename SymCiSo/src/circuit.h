#pragma once

#include <vector>
#include <memory>
#include <string>

#include "core/log.h"
#include "components/impedance.h"

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

		template<typename T, typename... Args>
		std::shared_ptr<T> add_component(const Args&... args)
		{
			std::shared_ptr<T> component = std::make_shared<T>(args...);

			// Add each node a weak reference to the component
			for (const std::shared_ptr<Node>& terminal : component->get_terminals())
				terminal->add_weak_ref_to_component(component);
			SYMCISO_CORE_TRACE("Added weak reference to {} terminals", *component);

			m_components.emplace_back(component);
			return component;
		}

		void print() const;

	private:
		std::vector<std::shared_ptr<Component>> m_components;
	};

} // namespace SymCiSo
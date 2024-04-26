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
			// Create a shared ptr to the new component (Resistor, Capacitor, ...)
			std::shared_ptr<T> component = std::make_shared<T>(args...);

			// Add to each terminal (Node) of the component a connection (weak ref to the component,
			// alongside with the position of the terminal)
			for (size_t terminal_num{ 0 }; terminal_num < component->get_num_terminals(); ++terminal_num)
			{
				// Get a shared ptr to the terminal (Node) at index "terminal_num"
				const std::shared_ptr<Node>& terminal{ component->get_terminals()[terminal_num] };
				// Create the connection
				const Connection connection{
					.component {component},
					.terminal_num{ terminal_num },
				};
				// Add the connection to the terminal (Node)
				terminal->add_connection(connection);
			}
			SYMCISO_CORE_TRACE("Added terminal connections to {}", *component);

			m_components.emplace_back(component);
			return component;
		}

		void print() const;

	private:
		std::vector<std::shared_ptr<Component>> m_components;
	};

} // namespace SymCiSo
#include "component.h"

#include "circuit.h"

namespace SymCiSo
{

	static void remove_connection_by_ptr(std::vector<Connection>& vec, const Component* const ptr)
	{
		vec.erase(std::remove_if(vec.begin(), vec.end(),
			[ptr](const Connection& conn) { return conn.component == ptr; }),
			vec.end());
	}

	Component::~Component()
	{
		// Remove this component (connection) from the nodes connected to this component
		for (const auto& terminal : get_terminals())
		{
			SYMCISO_CORE_TRACE("Removing component {} from connections {}", *this, *terminal);
			remove_connection_by_ptr(terminal->get_connections(), this);
		}

		SYMCISO_CORE_TRACE("Component instance destructed: {}", get_name());
	}

	Component::Component(Circuit& circuit, const size_t num_terminals, const std::string& name)
		: m_circuit(circuit), m_name(name)
	{
		for (size_t terminal_num{ 0 }; terminal_num < num_terminals; ++terminal_num)
		{
			// Create the connection
			const Connection connection{
				.component {this},
				.terminal_num{ terminal_num },
			};
			m_terminals.emplace_back(std::make_shared<Node>(get_circuit(), connection));
		}

		SYMCISO_CORE_TRACE("Component instance created: {}", get_name());
	}

	void Component::print() const
	{
		// Show the name of the component
		SYMCISO_CORE_INFO(*this);
		// Show each terminal
		for (size_t i{ 0 }; i < get_terminals().size(); ++i)
		{
			if (i != get_terminals().size() - 1)
				SYMCISO_CORE_INFO("{}Terminal {} is connected to: {}", char(195), i, *(get_terminals()[i]));
			else if (i == get_terminals().size() - 1)
				SYMCISO_CORE_INFO("{}Terminal {} is connected to: {}", char(192), i, *(get_terminals()[i]));
		}
	}

} // namespace SymCiSo

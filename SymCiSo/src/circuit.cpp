#include "circuit.h"

namespace SymCiSo
{

	Circuit::Circuit()
	{
		SYMCISO_CORE_INFO("[Circuit] Created");
	}

	Circuit::~Circuit()
	{
		SYMCISO_CORE_INFO("[Circuit] Destroying");
	}

	size_t Circuit::get_num_nodes() const
	{
		return m_nodes.size();
	}

	void Circuit::print() const
	{
		SYMCISO_CORE_INFO("Circuit");
		SYMCISO_INFO("Number of components: {}", get_num_components());
		SYMCISO_INFO("Number of nodes:      {}", get_num_nodes());
		for (const auto& component : get_components())
			component->print();
		SYMCISO_CORE_INFO("");
		check_for_unconnected_components();
	}

	void Circuit::check_for_unconnected_components() const
	{
		// Iterate over all components in the circuit
		for (const auto& component_rcp : get_components())
		{
			// To check if all terminals are disconnected
			size_t component_connected_terminals{ 0 };
			// Iterate over all terminals of the component
			for (const auto& terminal_rcp : component_rcp->get_terminals())
			{
				if (terminal_rcp->get_num_connections() == 0)
					SYMCISO_CORE_CRITICAL("Number of node connections is 0: must be at leat 1 (itself)");
				else if (terminal_rcp->get_num_connections() == 1)
					SYMCISO_WARN("Component {} has only 1 connection on terminal {}", *component_rcp, *terminal_rcp);
				else
					component_connected_terminals++;
			}
			// Check if all the terminals are connected
			if (component_connected_terminals == 0)
				SYMCISO_ERROR("Component {} has all terminals disconnected", *component_rcp);
		}
	}

} // namespace SymCiSo
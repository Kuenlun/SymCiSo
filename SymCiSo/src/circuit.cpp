#include "circuit.h"

namespace SymCiSo
{

	Circuit::Circuit()
	{
		SYMCISO_CORE_INFO("Circuit instance created");
	}

	Circuit::~Circuit()
	{
		SYMCISO_CORE_INFO("Circuit instance destructed");
	}

	size_t Circuit::get_num_nodes() const
	{
		// Assert that all weak_ptr to nodes in m_nodes are not expired
		// Otherwise some were not cleaned when a node expired
		const auto node_not_expired{ [](const std::weak_ptr<Node>& weak_ptr) {return !weak_ptr.expired(); } };
		if (!std::all_of(m_nodes.begin(), m_nodes.end(), node_not_expired))
			SYMCISO_CORE_ERROR("Circuit nodes vector contain weak_ptr to expired node");

		// Return the sise of the nodes vector
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
	}

} // namespace SymCiSo
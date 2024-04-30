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
	}

} // namespace SymCiSo
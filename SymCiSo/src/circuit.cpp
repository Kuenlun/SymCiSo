#include "circuit.h"

#include "core/log.h"

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
		SYMCISO_CORE_ERROR("Not implemented: get_num_nodes");
		return 0;
	}

	void Circuit::print() const
	{
		SYMCISO_CORE_INFO("Circuit");
		for (const auto& component : get_components())
			component->print();
		SYMCISO_CORE_INFO("");
	}

} // namespace SymCiSo
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

} // namespace SymCiSo
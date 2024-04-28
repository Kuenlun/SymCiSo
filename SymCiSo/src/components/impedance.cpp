#include "impedance.h"

#include "core/log.h"

namespace SymCiSo
{

	Impedance::Impedance(Circuit* const circuit_ptr, const std::string& name)
		: Component(circuit_ptr, 2, name),
		m_impedance(make_rcp<const Symbol>(get_name()))
	{
		SYMCISO_CORE_TRACE("Impedance instance created: {}", get_name());
	}

	Impedance::~Impedance()
	{
		SYMCISO_CORE_TRACE("Impedance instance destructed: {}", get_name());
	}

	Resistor::Resistor(Circuit* const circuit_ptr, const std::string& name)
		: Impedance(circuit_ptr, name)
	{
		SYMCISO_CORE_TRACE("Resistor instance created: {}", get_name());
	}

	Resistor::~Resistor()
	{
		SYMCISO_CORE_TRACE("Resistor instance destructed: {}", get_name());
	}

	Capacitor::Capacitor(Circuit* const circuit_ptr, const std::string& name)
		: Impedance(circuit_ptr, name)
	{
		SYMCISO_CORE_TRACE("Capacitor instance created: {}", get_name());
	}

	Capacitor::~Capacitor()
	{
		SYMCISO_CORE_TRACE("Capacitor instance destructed: {}", get_name());
	}

	Inductor::Inductor(Circuit* const circuit_ptr, const std::string& name)
		: Impedance(circuit_ptr, name)
	{
		SYMCISO_CORE_TRACE("Inductor instance created: {}", get_name());
	}

	Inductor::~Inductor()
	{
		SYMCISO_CORE_TRACE("Inductor instance destructed: {}", get_name());
	}

} // namespace SymCiSo

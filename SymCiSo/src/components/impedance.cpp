#include "impedance.h"

namespace SymCiSo
{

	Impedance::Impedance(Circuit& circuit, const std::string& name)
		: Component(circuit, 2, name),
		m_impedance(make_rcp<const Symbol>(get_name()))
	{
		SYMCISO_CORE_TRACE("[Impedance] Created: {}", get_name());
	}

	Impedance::~Impedance()
	{
		SYMCISO_CORE_TRACE("[Impedance] Destroying: {}", get_name());
	}

	Resistor::Resistor(Circuit& circuit, const std::string& name)
		: Impedance(circuit, name)
	{
		SYMCISO_CORE_TRACE("[Resistor] Created: {}", get_name());
	}

	Resistor::~Resistor()
	{
		SYMCISO_CORE_TRACE("[Resistor] Destroying: {}", get_name());
	}

	Capacitor::Capacitor(Circuit& circuit, const std::string& name)
		: Impedance(circuit, name)
	{
		SYMCISO_CORE_TRACE("[Capacitor] Created: {}", get_name());
	}

	Capacitor::~Capacitor()
	{
		SYMCISO_CORE_TRACE("[Capacitor] Destroying: {}", get_name());
	}

	Inductor::Inductor(Circuit& circuit, const std::string& name)
		: Impedance(circuit, name)
	{
		SYMCISO_CORE_TRACE("[Inductor] Created: {}", get_name());
	}

	Inductor::~Inductor()
	{
		SYMCISO_CORE_TRACE("[Inductor] Destroying: {}", get_name());
	}

} // namespace SymCiSo

#include "impedance.h"

#include "core/log.h"

namespace SymCiSo
{

	Impedance::Impedance(const std::string& name)
		: m_impedance{ make_rcp<const Symbol>(name) }
	{
		for (std::shared_ptr<Node>& terminal : m_terminals)
			terminal = std::make_shared<Node>();
	}

	Resistor::Resistor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Resistor instance created");
	}

	Capacitor::Capacitor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Resistor instance created");
	}

	Inductor::Inductor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Resistor instance created");
	}

} // namespace SymCiSo

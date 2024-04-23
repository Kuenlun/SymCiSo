#include "impedance.h"

#include "core/log.h"

namespace SymCiSo
{

	Impedance::Impedance(const std::string& name)
		: Component(2),
			m_impedance{ make_rcp<const Symbol>(name) }
	{
		SYMCISO_CORE_TRACE("Impedance instance created");
	}

	Resistor::Resistor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Resistor instance created");
	}

	Capacitor::Capacitor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Capacitor instance created");
	}

	Inductor::Inductor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Inductor instance created");
	}

} // namespace SymCiSo

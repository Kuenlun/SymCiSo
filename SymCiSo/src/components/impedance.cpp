#include "impedance.h"

#include "core/log.h"

namespace SymCiSo
{

	Impedance::Impedance(const std::string& name)
		: Component(2, name),
		m_impedance(make_rcp<const Symbol>(get_name()))
	{
		SYMCISO_CORE_TRACE("Impedance instance created: {}", get_name());
	}

	Impedance::~Impedance()
	{
		SYMCISO_CORE_TRACE("Impedance instance destructed: {}", get_name());
	}

	Resistor::Resistor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Resistor instance created: {}", get_name());
	}

	Resistor::~Resistor()
	{
		SYMCISO_CORE_TRACE("Resistor instance destructed: {}", get_name());
	}

	Capacitor::Capacitor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Capacitor instance created: {}", get_name());
	}

	Capacitor::~Capacitor()
	{
		SYMCISO_CORE_TRACE("Capacitor instance destructed: {}", get_name());
	}

	Inductor::Inductor(const std::string& name)
		: Impedance(name)
	{
		SYMCISO_CORE_INFO("Inductor instance created: {}", get_name());
	}

	Inductor::~Inductor()
	{
		SYMCISO_CORE_TRACE("Inductor instance destructed: {}", get_name());
	}

} // namespace SymCiSo

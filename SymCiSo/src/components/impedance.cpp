#include "impedance.h"

namespace SymCiSo
{

	Impedance::Impedance(const std::string& name)
		: m_impedance{ make_rcp<const Symbol>(name) }
	{
	}

	Resistor::Resistor(const std::string& name) : Impedance(name) {}

	Capacitor::Capacitor(const std::string& name) : Impedance(name) {}

	Inductor::Inductor(const std::string& name) : Impedance(name) {}

} // namespace SymCiSo

#pragma once

#include "component.h"

namespace SymCiSo 
{

	class Impedance : public Component
	{
	public:
		Impedance(const std::string& name);

		inline RCP<const Symbol> get_impedance() const { return m_impedance; }

	private:
		RCP<const Symbol> m_impedance;
	};

	class Resistor : public Impedance
	{
	public:
		Resistor(const std::string& name);

		inline RCP<const Symbol> get_resistance() const { return get_impedance(); }
	};

	class Capacitor : public Impedance
	{
	public:
		Capacitor(const std::string& name);

		inline RCP<const Symbol> get_capacitance() const { return get_impedance(); }
	};

	class Inductor : public Impedance
	{
	public:
		Inductor(const std::string& name);

		inline RCP<const Symbol> get_inductance() const { return get_impedance(); }
	};

} // namespace SymCiSo

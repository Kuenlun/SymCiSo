#pragma once

#include <string>

#include "core/core.h"
#include "core/log.h"
#include "component.h"

namespace SymCiSo
{

	class Impedance : public Component
	{
	public:
		virtual const char* get_class_name() const override { return "Impedance"; }

		Impedance(Circuit& circuit, const std::string& name);
		virtual ~Impedance();

		inline RCP<const Symbol> get_impedance() const { return m_impedance; }

	private:
		RCP<const Symbol> m_impedance;
	};

	class Resistor : public Impedance
	{
	public:
		const char* get_class_name() const override { return "Resistor"; }

		Resistor(Circuit& circuit, const std::string& name);
		~Resistor();

		inline RCP<const Symbol> get_resistance() const { return get_impedance(); }
	};

	class Capacitor : public Impedance
	{
	public:
		const char* get_class_name() const override { return "Capacitor"; }

		Capacitor(Circuit& circuit, const std::string& name);
		~Capacitor();

		inline RCP<const Symbol> get_capacitance() const { return get_impedance(); }
	};

	class Inductor : public Impedance
	{
	public:
		const char* get_class_name() const override { return "Inductor"; }

		Inductor(Circuit& circuit, const std::string& name);
		~Inductor();

		inline RCP<const Symbol> get_inductance() const { return get_impedance(); }
	};

} // namespace SymCiSo

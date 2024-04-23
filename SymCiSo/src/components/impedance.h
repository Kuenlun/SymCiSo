#pragma once

#include <array>
#include <memory>

#include <symengine/symbol.h>

#include "node.h"

namespace SymCiSo
{

	using SymEngine::Symbol;
	using SymEngine::RCP;
	using SymEngine::make_rcp;

	class Impedance
	{
	public:
		Impedance(const std::string& name);

		inline RCP<const Symbol> get_impedance() const { return m_impedance; }
		std::shared_ptr<Node>& get_terminal(const size_t idx) { return m_terminals[idx]; }
			
	private:
		RCP<const Symbol> m_impedance;
		std::array<std::shared_ptr<Node>, 2> m_terminals;
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

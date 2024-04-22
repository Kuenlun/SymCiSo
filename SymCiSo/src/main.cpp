#include <iostream>
#include <symengine/expression.h>

namespace SymCiSo
{

	using SymEngine::Symbol;
	using SymEngine::RCP;
	using SymEngine::make_rcp;


	class Impedance
	{
	public:
		Impedance(const std::string& name)
			: m_impedance{ make_rcp<const Symbol>(name) }
		{
		}

		inline RCP<const Symbol> get_impedance() const { return m_impedance; }

	private:
		RCP<const Symbol> m_impedance;
	};

	class Resistor : private Impedance
	{
	public:
		Resistor(const std::string& name) : Impedance(name) {}

		inline RCP<const Symbol> get_resistance() const { return get_impedance(); }
	};

	class Capacitor : private Impedance
	{
	public:
		Capacitor(const std::string& name) : Impedance(name) {}

		inline RCP<const Symbol> get_capacitance() const { return get_impedance(); }
	};

	class Inductance : private Impedance
	{
	public:
		Inductance(const std::string& name) : Impedance(name) {}

		inline RCP<const Symbol> get_inductance() const { return get_impedance(); }
	};

} // namespace SymCiSo


int main()
{
	SymCiSo::Resistor r1("R1");

	const auto r1_resistance{ r1.get_resistance() };
	const auto sum{ SymEngine::add(r1_resistance, SymEngine::number(1)) };
	std::cout << SymEngine::Expression(sum) << std::endl;
}

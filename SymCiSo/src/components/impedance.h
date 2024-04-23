#include <symengine/symbol.h>

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

	private:
		RCP<const Symbol> m_impedance;
	};

	class Resistor : private Impedance
	{
	public:
		Resistor(const std::string& name);

		inline RCP<const Symbol> get_resistance() const { return get_impedance(); }
	};

	class Capacitor : private Impedance
	{
	public:
		Capacitor(const std::string& name);

		inline RCP<const Symbol> get_capacitance() const { return get_impedance(); }
	};

	class Inductor : private Impedance
	{
	public:
		Inductor(const std::string& name);

		inline RCP<const Symbol> get_inductance() const { return get_impedance(); }
	};

} // namespace SymCiSo

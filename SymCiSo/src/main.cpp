#include <iostream>

#include <symengine/expression.h>

#include "core/log.h"
#include "components/impedance.h"

int main()
{
	SymCiSo::Log::init();

	SymCiSo::Resistor r1("R1");
	SymCiSo::Capacitor c1("C1");
	SymCiSo::Inductor i1("I1");


	const auto r1_resistance{ r1.get_resistance() };
	const auto sum{ SymEngine::add(r1_resistance, SymEngine::number(1)) };
	SYMCISO_INFO("Expression: {}", SymEngine::Expression(sum));
}

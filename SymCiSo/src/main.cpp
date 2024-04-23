#include <iostream>

#include "core/log.h"
#include "components/impedance.h"

int main()
{
	SymCiSo::Log::init();

	SymCiSo::Resistor r1("R1");
	SymCiSo::Capacitor c1("C1");
	SymCiSo::Inductor i1("I1");

	SymCiSo::Node::connect(r1.get_terminal(0), c1.get_terminal(0));

	SYMCISO_INFO("R1 resistance is : {}", *r1.get_resistance());
}

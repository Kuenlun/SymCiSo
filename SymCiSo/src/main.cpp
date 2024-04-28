#include <iostream>

#include <symciso.h>

int main()
{
	SymCiSo::Log::init();

	SymCiSo::Circuit circuit;

	std::shared_ptr<SymCiSo::Resistor> r1_ptr{ circuit.add_component<SymCiSo::Resistor>("R1") };
	std::shared_ptr<SymCiSo::Resistor> r2_ptr{ circuit.add_component<SymCiSo::Resistor>("R2") };
	std::shared_ptr<SymCiSo::Resistor> r3_ptr{ circuit.add_component<SymCiSo::Resistor>("R3") };
	std::shared_ptr<SymCiSo::Capacitor> c1_ptr{ circuit.add_component<SymCiSo::Capacitor>("C1") };
	std::shared_ptr<SymCiSo::Capacitor> c2_ptr{ circuit.add_component<SymCiSo::Capacitor>("C2") };

	circuit.print();
	SymCiSo::Node::connect(r1_ptr->get_terminal(0), r2_ptr->get_terminal(0));
	circuit.print();
	SymCiSo::Node::connect(c1_ptr->get_terminal(0), c2_ptr->get_terminal(0));
	circuit.print();
	SymCiSo::Node::connect(r2_ptr->get_terminal(0), c1_ptr->get_terminal(0));
	circuit.print();
	SymCiSo::Node::connect(r3_ptr->get_terminal(0), c1_ptr->get_terminal(0));
	circuit.print();

	SYMCISO_INFO("R1 resistance is : {}", *(r1_ptr->get_resistance()));
}

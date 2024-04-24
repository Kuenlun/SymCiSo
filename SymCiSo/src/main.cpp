#include <iostream>

#include "core/log.h"

#include "circuit.h"

int main()
{
	SymCiSo::Log::init();

	SymCiSo::Circuit circuit;

	std::shared_ptr<SymCiSo::Resistor> r1{ circuit.add_component<SymCiSo::Resistor>("R1") };
	std::shared_ptr<SymCiSo::Capacitor> c1{ circuit.add_component<SymCiSo::Capacitor>("C1") };

	SYMCISO_INFO("Number of components: {}", circuit.get_num_components());
	//SYMCISO_INFO("Number of circuit nodes: {}", circuit.get_num_nodes());
	SymCiSo::Node::connect(r1->get_terminal(0), c1->get_terminal(0));
	SymCiSo::Node::connect(r1->get_terminal(1), c1->get_terminal(1));
	circuit.print();

	SYMCISO_INFO("R1 resistance is : {}", *(r1->get_resistance()));
}

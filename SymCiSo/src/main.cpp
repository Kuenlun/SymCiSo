#include <iostream>

#include "core/log.h"

#include "circuit.h"

int main()
{
	SymCiSo::Log::init();

	SymCiSo::Circuit circuit;

	std::shared_ptr<SymCiSo::Resistor> r1_ptr{ circuit.add_component<SymCiSo::Resistor>("R1") };
	std::shared_ptr<SymCiSo::Capacitor> c1_ptr{ circuit.add_component<SymCiSo::Capacitor>("C1") };

	SYMCISO_INFO("Number of components: {}", circuit.get_num_components());
	//SYMCISO_INFO("Number of circuit nodes: {}", circuit.get_num_nodes());
	circuit.print();
	SYMCISO_INFO("Connecttin {} {} to {} {}", *r1_ptr, 0, *c1_ptr, 0);
	SymCiSo::Node::connect(r1_ptr->get_terminal(0), c1_ptr->get_terminal(0));
	circuit.print();
	SYMCISO_INFO("Connecttin {} {} to {} {}", *r1_ptr, 1, *c1_ptr, 1);
	SymCiSo::Node::connect(r1_ptr->get_terminal(1), c1_ptr->get_terminal(1));
	circuit.print();
	SYMCISO_INFO("Connecttin {} {} to {} {}", *r1_ptr, 0, *r1_ptr, 0);
	SymCiSo::Node::connect(r1_ptr->get_terminal(0), r1_ptr->get_terminal(0));
	circuit.print();
	SYMCISO_INFO("Connecttin {} {} to {} {}", *r1_ptr, 0, *r1_ptr, 1);
	SymCiSo::Node::connect(r1_ptr->get_terminal(0), r1_ptr->get_terminal(1));
	circuit.print();

	SYMCISO_INFO("R1 resistance is : {}", *(r1_ptr->get_resistance()));
}

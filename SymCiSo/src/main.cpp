#include <iostream>

#include <symciso.h>

int main()
{
	SymCiSo::Log::init();

	SymCiSo::Circuit circuit;

	std::shared_ptr<SymCiSo::Resistor> r1_ptr{ circuit.add_component<SymCiSo::Resistor>("R1") };
	std::shared_ptr<SymCiSo::Resistor> r2_ptr{ circuit.add_component<SymCiSo::Resistor>("R2") };
	std::shared_ptr<SymCiSo::Resistor> r3_ptr{ circuit.add_component<SymCiSo::Resistor>("R3") };
	std::shared_ptr<SymCiSo::Resistor> r4_ptr{ circuit.add_component<SymCiSo::Resistor>("R4") };
	std::shared_ptr<SymCiSo::Resistor> c1_ptr{ circuit.add_component<SymCiSo::Resistor>("C1") };

	circuit.print();
	SymCiSo::Node::connect(r1_ptr->get_terminal(0), r2_ptr->get_terminal(1));
	circuit.print();
	SymCiSo::Node::connect(r2_ptr->get_terminal(0), r3_ptr->get_terminal(1));
	circuit.print();
	SymCiSo::Node::connect(r3_ptr->get_terminal(0), r4_ptr->get_terminal(1));
	circuit.print();
	SymCiSo::Node::connect(r4_ptr->get_terminal(0), r1_ptr->get_terminal(1));
	circuit.print();
	SymCiSo::Node::connect(c1_ptr->get_terminal(0), r2_ptr->get_terminal(1));
	circuit.print();

	SYMCISO_INFO("R1 resistance is : {}", *(r1_ptr->get_resistance()));

	const SymCiSo::VoltageDiff vdiff(r1_ptr->get_terminal(0), r3_ptr->get_terminal(1));
	SYMCISO_INFO("VoltageDiff : {}", vdiff);

	std::vector<std::weak_ptr<SymCiSo::Node>> path;
	path = vdiff.calculate_voltage_path(path);

	for (const auto& node_wp : path)
		if (const auto locked = node_wp.lock())
			SYMCISO_INFO("{}", *locked);
		else
			SYMCISO_ERROR("Could not lock the node");
}

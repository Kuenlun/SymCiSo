#include "node.h"

namespace SymCiSo
{

	Node::Node(Circuit* const circuit_ptr)
		: m_circuit_ptr(circuit_ptr)
	{
		SYMCISO_CORE_TRACE("Node instance created");
	}

	Node::~Node()
	{
		// Clean the weak_ref to the node in circuit vector of nodes
		auto& vec_nodes = get_circuit_ptr()->get_nodes();
		auto it = std::remove_if(vec_nodes.begin(), vec_nodes.end(), [](const std::weak_ptr<Node>& wp) { return wp.expired(); });

		// Check if any elements were removed before erasing
		if (it != vec_nodes.end()) {
			vec_nodes.erase(it, vec_nodes.end());
		}

		SYMCISO_CORE_TRACE("Node instance destructed {}", *this);
	}

	void Node::add_connection(const Connection& connection)
	{
		m_connections.emplace_back(connection);
	}

	void Node::connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other)
	{
		SYMCISO_CORE_TRACE("Connecting node {} and {}", *self, *other);
		// Check if the nodes are the same
		if (self == other)
		{
			SYMCISO_CORE_WARN("Nodes already connected");
			// Check if the references are the same
			if (&self == &other)
				SYMCISO_CORE_ERROR("Trying to connect a node to itself");
			return;
		}

		// Add the "other" connection to "self" connection
		for (auto& connection : other->get_connections())
			self->get_connections().push_back(connection);

		// Not only should self assigned to other, but to all terminals connected to "other".
		// Note: "other" is included in "other"'s connections.
		// Note: If "other" is not referenced by any component it will die automatically
		for (const auto& connection : other->get_connections())
		{
			if (const auto locked = connection.component.lock())
				locked->get_terminals()[connection.terminal_num] = self;
			else
				SYMCISO_CORE_WARN("Connection component is dead");
		}
		SYMCISO_CORE_INFO("Node {} connected", *self);
	}

	Component::Component(Circuit* const circuit_ptr,
		const size_t num_terminals,
		const std::string& name)
		: m_circuit_ptr(circuit_ptr), m_name(name)
	{
		for (size_t i{ 0 }; i < num_terminals; ++i)
			m_terminals.emplace_back(std::make_shared<Node>(get_circuit_ptr()));

		SYMCISO_CORE_TRACE("Component instance created: {}", get_name());
	}

	void Component::print() const
	{
		// Show the name of the component
		SYMCISO_CORE_INFO(*this);
		// Show each terminal
		for (size_t i{ 0 }; i < get_terminals().size(); ++i)
		{
			if (i != get_terminals().size() - 1)
				SYMCISO_CORE_INFO("{}Terminal {} is connected to: {}", char(195), i, *(get_terminals()[i]));
			else if (i == get_terminals().size() - 1)
				SYMCISO_CORE_INFO("{}Terminal {} is connected to: {}", char(192), i, *(get_terminals()[i]));
		}
	}

} // namespace SymCiSo

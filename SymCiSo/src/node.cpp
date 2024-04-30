#include "node.h"

#include "circuit.h"

namespace SymCiSo
{

	Node::Node(Circuit& circuit, const Connection connection)
		: m_circuit(circuit)
	{
		// Add the connection from the component that created the Node
		m_connections.emplace_back(connection);
		// Add a reference to the circuit of the current node
		get_circuit().get_nodes().push_back(this);
		SYMCISO_CORE_TRACE("[Node] Created: {}", *this);
	}

	Node::~Node()
	{
		SYMCISO_CORE_TRACE("[Node] Destroying: {}", *this);

		// Remove this node from the circuit vector of nodes
		remove_ptr_from_vector(get_circuit().get_nodes(), this);
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
			connection.component->get_terminals()[connection.terminal_num] = self;
		SYMCISO_CORE_INFO("Node {} connected", *self);
	}

} // namespace SymCiSo

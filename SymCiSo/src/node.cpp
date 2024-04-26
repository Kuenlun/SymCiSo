#include "node.h"

#include "core/log.h"

namespace SymCiSo
{

	Node::Node()
	{
		SYMCISO_CORE_TRACE("Node instance created");
	}

	Node::~Node()
	{
		SYMCISO_CORE_TRACE("Node instance destructed");
	}

	void Node::add_connection(const Connection& connection)
	{
		m_connections.emplace_back(connection);
	}

	void Node::connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other)
	{
		// Check if the nodes are the same
		if (self == other)
		{
			SYMCISO_CORE_WARN("Nodes already connected");
			return;
		}

		// Add the "other" connection to "self" connection
		for (auto& connection : other->get_connections())
			self->get_connections().push_back(connection);

		// Missing checks
		SYMCISO_CORE_WARN("Additional checks not done in the connection!");

		// Assign "self" node to "other"
		// Note: If "other" is not referenced by any component it will die automatically
		other = self;
		SYMCISO_CORE_TRACE("Node connected");
	}

} // namespace SymCiSo

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

	void Node::connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other)
	{
		other = self;
		SYMCISO_CORE_TRACE("Node connected");
	}

} // namespace SymCiSo

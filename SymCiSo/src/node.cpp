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

	void Node::add_weak_ref_to_component(const std::weak_ptr<Component> component)
	{
		m_components.emplace_back(component);
	}

	void Node::connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other)
	{
		// Get the components connected to other
		for (auto& component : other->get_components())
			self->get_components().push_back(component);

		// Missing checks
		SYMCISO_CORE_WARN("Additional checks not done in the connection!");
			
		// Assign "self" node to "other"
		// Note: If "other" is not referenced by any component it will die automatically
		other = self;
		SYMCISO_CORE_TRACE("Node connected");
	}

} // namespace SymCiSo

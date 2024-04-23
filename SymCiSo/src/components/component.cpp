#include "component.h"

#include "core/log.h"

namespace SymCiSo
{

	Component::Component(const size_t num_terminals)
	{
		for (size_t i{ 0 }; i < num_terminals; ++i)
			m_terminals.emplace_back(std::make_shared<Node>());
		SYMCISO_CORE_TRACE("Component instance created");
	}

	Component::~Component()
	{
		SYMCISO_CORE_TRACE("Component instance destructed");
	}

} // namespace SymCiSo

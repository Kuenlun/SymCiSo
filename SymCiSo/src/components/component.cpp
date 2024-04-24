#include "component.h"

#include "core/log.h"

namespace SymCiSo
{

	Component::Component(const size_t num_terminals, const std::string& name)
		: m_name(name)
	{
		for (size_t i{ 0 }; i < num_terminals; ++i)
			m_terminals.emplace_back(std::make_shared<Node>());

		SYMCISO_CORE_TRACE("Component instance created: {}", get_name());
	}

	Component::~Component()
	{
		SYMCISO_CORE_TRACE("Component instance destructed: {}", get_name());
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
			else if ( i == get_terminals().size() - 1)
				SYMCISO_CORE_INFO("{}Terminal {} is connected to: {}", char(192), i, *(get_terminals()[i]));

		}
	}

} // namespace SymCiSo

#pragma once

#include <memory>

#include "core/core.h"
#include "core/log.h"
#include "components/component.h"

namespace SymCiSo
{

	class Connection
	{
	public:
		Connection(Component* component, const size_t terminal_num);

		size_t get_terminal_num() const { return m_terminal_num; }
		Component* get_component() const { return m_component; }

	private:
		Component* m_component;
		size_t	m_terminal_num;
	};

	template<typename OStream>
	inline OStream& operator<<(OStream& os, const Connection& conn)
	{
		// Show the component and the terminal number
		return os << *conn.get_component() << "->" << conn.get_terminal_num();
	}

} // namespace SymCiSo
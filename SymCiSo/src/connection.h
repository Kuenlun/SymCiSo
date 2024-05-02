#pragma once

#include <memory>

#include "core/core.h"
#include "core/log.h"

namespace SymCiSo
{

	struct Connection
	{
		Component* component;
		size_t	terminal_num;
	};

	template<typename OStream>
	inline OStream& operator<<(OStream& os, const Connection& conn)
	{
		// Show the component and the terminal number
		return os << *conn.component << "->" << conn.terminal_num;
	}

} // namespace SymCiSo
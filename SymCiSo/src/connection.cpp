#include "connection.h"

namespace SymCiSo
{

	Connection::Connection(Component* component, const size_t terminal_num)
		: m_component(component), m_terminal_num(terminal_num)
	{
	}

} // namespace SymCiSo
#include "connection.h"

namespace SymCiSo
{

	Connection::Connection(Component* component, const size_t terminal_num)
		: m_component(component), m_terminal_num(terminal_num)
	{
	}

	std::vector<Connection> Connection::get_voltage_diff_from_this() const
	{
		SYMCISO_CORE_CRITICAL("Not implemented");
		return std::vector<Connection>();
	}

} // namespace SymCiSo
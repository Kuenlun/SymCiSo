#pragma once

#include <vector>
#include <memory>

#include "core/core.h"
#include "core/log.h"
#include "circuit.h"

namespace SymCiSo
{

	class Node
	{
	public:
		Node(Circuit* const circuit_ptr);

		~Node();

		void add_connection(const Connection& connection);

		inline const std::vector<Connection>& get_connections() const { return m_connections; }
		inline std::vector<Connection>& get_connections() { return m_connections; }
		inline Circuit* const get_circuit_ptr() { return m_circuit_ptr; }

	public:
		static void connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other);

	private:
		Circuit* const m_circuit_ptr;
		std::vector<Connection> m_connections;
	};

	template<typename OStream>
	inline OStream& operator<<(OStream& os, const Node& node)
	{
		os << "[";
		bool first{ true };
		for (const auto& connection : node.get_connections())
		{
			if (!first)
				os << ", ";
			first = false;

			// Show the component
			if (const auto& locked_component = connection.component.lock())
				os << *locked_component;
			else
				os << "?";
			// Show the terminal num
			os << "->" << connection.terminal_num;
		}
		return os << "]";
	}

} // namespace SymCiSo

#pragma once

#include <vector>
#include <memory>

#include "core/core.h"
#include "core/log.h"
#include "components/component.h"
#include "connection.h"

namespace SymCiSo
{

	class Node
	{
	public:
		Node(Circuit& circuit, const Connection connection);

		~Node();

		void add_connection(const Connection& connection);

		const std::vector<Connection>& get_connections() const { return m_connections; }
		std::vector<Connection>& get_connections() { return m_connections; }
		size_t get_num_connections() const { return get_connections().size(); }
		Circuit& get_circuit() { return m_circuit; }

	public:
		static void connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other);

	private:
		Circuit& m_circuit;
		std::vector<Connection> m_connections;
	};

	template<typename OStream>
	inline OStream& operator<<(OStream& os, const Node& node)
	{
		os << "[";
		bool first{ true };
		for (const auto& conn : node.get_connections())
		{
			if (!first)
				os << ", ";
			first = false;
			// Show the connection
			os << conn;
		}
		return os << "]";
	}

} // namespace SymCiSo

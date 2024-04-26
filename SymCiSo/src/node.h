#pragma once

#include <vector>
#include <memory>

#include "components/component.h"

namespace SymCiSo
{

	class Component;

	struct Connection
	{
		std::weak_ptr<Component> component;
		size_t	terminal_num;
	};

	class Node
	{
	public:
		Node();

		~Node();

		void add_connection(const Connection& connection);

		inline const std::vector<Connection>& get_connections() const { return m_connections; }
		inline std::vector<Connection>& get_connections() { return m_connections; }

	public:
		static void connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other);

	private:
		std::vector<Connection> m_connections;
	};

} // namespace SymCiSo

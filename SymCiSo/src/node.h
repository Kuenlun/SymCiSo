#pragma once

#include <memory>

namespace SymCiSo
{

	class Node
	{
	public:
		Node();

		~Node();

		static void connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other);
	};

} // namespace SymCiSo

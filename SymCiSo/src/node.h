#pragma once

#include <vector>
#include <memory>

#include "components/component.h"

namespace SymCiSo
{

	class Component;

	class Node
	{
	public:
		Node(const std::weak_ptr<Component> component);

		~Node();

		static void connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other);

	private:
		std::vector<std::weak_ptr<Component>> m_components;
	};

} // namespace SymCiSo

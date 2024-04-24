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
		Node();

		~Node();

		void add_weak_ref_to_component(const std::weak_ptr<Component> component);

		inline const std::vector<std::weak_ptr<Component>>& get_components() const { return m_components; }
		inline std::vector<std::weak_ptr<Component>>& get_components() { return m_components; }

	public:
		static void connect(const std::shared_ptr<Node>& self, std::shared_ptr<Node>& other);

	private:
		std::vector<std::weak_ptr<Component>> m_components;
	};

} // namespace SymCiSo

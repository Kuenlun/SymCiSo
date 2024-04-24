#pragma once

#include <vector>
#include <memory>

#include <symengine/symbol.h>

#include "node.h"

namespace SymCiSo
{

	using SymEngine::Symbol;
	using SymEngine::RCP;
	using SymEngine::make_rcp;

	class Node;

	class Component
	{
	public:
		~Component();

		inline std::shared_ptr<Node>& get_terminal(const size_t idx) { return m_terminals[idx]; }

	protected:
		Component(const std::weak_ptr<Component> self, const size_t num_terminals);

	private:
		std::vector<std::shared_ptr<Node>> m_terminals;
	};

} // namespace SymCiSo

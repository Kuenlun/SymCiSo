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
		virtual ~Component();

		inline std::shared_ptr<Node>& get_terminal(const size_t idx) { return m_terminals[idx]; }

		inline const std::vector<std::shared_ptr<Node>>& get_terminals() const { return m_terminals; }
		inline std::vector<std::shared_ptr<Node>>& get_terminals() { return m_terminals; }

		inline const std::string& get_name() const { return m_name; }

		void print() const;

	protected:
		Component(const size_t num_terminals, const std::string& name);

	private:
		std::string m_name;
		std::vector<std::shared_ptr<Node>> m_terminals;
	};

} // namespace SymCiSo

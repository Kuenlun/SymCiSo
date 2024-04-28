#pragma once

#include <vector>
#include <memory>

#include <symengine/symbol.h>

#include "core/core.h"
#include "core/log.h"

namespace SymCiSo
{

	using SymEngine::Symbol;
	using SymEngine::RCP;
	using SymEngine::make_rcp;

	class Component
	{
	public:
		virtual const char* get_class_name() const { return "Component"; }

		virtual ~Component();

		inline std::shared_ptr<Node>& get_terminal(const size_t idx) { return m_terminals[idx]; }
		inline const std::vector<std::shared_ptr<Node>>& get_terminals() const { return m_terminals; }
		inline std::vector<std::shared_ptr<Node>>& get_terminals() { return m_terminals; }
		inline size_t get_num_terminals() const { return m_terminals.size(); };

		inline const std::string& get_name() const { return m_name; }
		inline Circuit* const get_circuit_ptr() { return m_circuit_ptr; }

		void print() const;

	protected:
		Component(Circuit* const circuit,
			const size_t num_terminals,
			const std::string& name);

	private:
		Circuit* const m_circuit_ptr;
		std::string m_name;
		std::vector<std::shared_ptr<Node>> m_terminals;
	};

	template<typename OStream>
	inline OStream& operator<<(OStream& os, const Component& component)
	{
		return os << component.get_name();
	}

} // namespace SymCiSo

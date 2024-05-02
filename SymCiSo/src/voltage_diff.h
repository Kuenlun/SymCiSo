#pragma once

#include <array>
#include <memory>

#include "core/core.h"
#include "core/log.h"
#include "node.h"

namespace SymCiSo
{

	class VoltageDiff
	{
	public:
		VoltageDiff(const std::weak_ptr<Node> node_a, const std::weak_ptr<Node> node_b);

		void calculate_voltage_path() const;

		const std::weak_ptr<Node> get_node_a() const { return m_node_a; }
		const std::weak_ptr<Node> get_node_b() const { return m_node_b; }

	private:
		const std::weak_ptr<Node> m_node_a;
		const std::weak_ptr<Node> m_node_b;
	};


	template<typename OStream>
	inline OStream& operator<<(OStream& os, const VoltageDiff& vdiff)
	{
		if (const auto locked = vdiff.get_node_a().lock())
			os << *locked;
		else
			os << '?';

		os << ", ";

		if (const auto locked = vdiff.get_node_b().lock())
			os << *locked;
		else
			os << '?';

		return os;
	}

} // namespace SymCiSo
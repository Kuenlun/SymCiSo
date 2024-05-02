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
		VoltageDiff(const std::weak_ptr<Node> node_a, const std::weak_ptr<Node> node_b)
			: m_nodes{ node_a, node_b }
		{
		}

		const std::array<std::weak_ptr<Node>, 2>& get_nodes() const { return m_nodes; }

	private:
		const std::array<std::weak_ptr<Node>, 2> m_nodes;
	};


	template<typename OStream>
	inline OStream& operator<<(OStream& os, const VoltageDiff& vdiff)
	{
		for (const auto& node_wp : vdiff.get_nodes())
		{
			if (const auto locked = node_wp.lock())
				os << *locked << ", ";
			else
				os << '?' << ", ";
		}
		return os;
	}

} // namespace SymCiSo
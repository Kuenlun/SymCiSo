#include "voltage_diff.h"

namespace SymCiSo
{

	VoltageDiff::VoltageDiff(const std::weak_ptr<Node> node_a, const std::weak_ptr<Node> node_b)
		: m_node_a(node_a), m_node_b(node_b)
	{
	}

	void VoltageDiff::calculate_voltage_path() const
	{
		// Lock the weak pointers
		const auto node_a{ get_node_a().lock() };
		const auto node_b{ get_node_b().lock() };
		if (!node_a)
			SYMCISO_CORE_ERROR("Node A has expired");
		if (!node_b)
			SYMCISO_CORE_ERROR("Node B has expired");
		if (!node_a || !node_b)
			return;

		// Iterate over the node connections
		for (const auto& conn : node_a->get_connections())
		{
			SYMCISO_CORE_CRITICAL("Not implemented");
			conn.get_voltage_diff_from_this();
		}
	}

} // namespace SymCiSo
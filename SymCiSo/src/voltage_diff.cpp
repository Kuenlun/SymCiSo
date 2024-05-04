#include "voltage_diff.h"

namespace SymCiSo
{

	VoltageDiff::VoltageDiff(const std::weak_ptr<Node> node_a, const std::weak_ptr<Node> node_b)
		: m_node_a(node_a), m_node_b(node_b)
	{
	}

	std::vector<std::weak_ptr<Node>>& VoltageDiff::calculate_voltage_path(std::vector<std::weak_ptr<Node>>& path) const
	{
		// Lock the weak pointers
		const auto node_start{ get_node_a().lock() };
		const auto node_destination{ get_node_b().lock() };
		if (!node_start)
			SYMCISO_CORE_ERROR("Start node has expired");
		if (!node_destination)
			SYMCISO_CORE_ERROR("Destination node has expired");
		if (!node_start || !node_destination)
			return path;

		find_path(node_start, node_destination, path);
		return path;
	}

	static bool is_node_in_path(const std::shared_ptr<Node>& node, const std::vector<std::weak_ptr<Node>>& path) {
		return std::find_if(path.begin(), path.end(),
			[&](const std::weak_ptr<Node>& weak_node)
			{
				if (auto shared_node = weak_node.lock())
					return shared_node == node;
				return false;
			}) != path.end();
	}

	bool VoltageDiff::find_path(const std::shared_ptr<Node>& node_start,
		const std::shared_ptr<Node>& node_destination,
		std::vector<std::weak_ptr<Node>>& path, size_t depth) const
	{
		if (depth == 0)
			SYMCISO_CORE_TRACE("{}Node {}", std::string(2 * depth, ' '), *node_start);

		// Add the node_adjacent to the path
		path.emplace_back(node_start);

		// Check if we have reached the destination node
		if (node_start == node_destination)
		{
			SYMCISO_CORE_INFO("{}Path found", std::string(2 * depth, ' '));
			return true;
		}
		// Iterate over the connections of the current node
		for (const auto& conn : node_start->get_connections())
		{
			SYMCISO_CORE_TRACE("{}Conn {}", std::string(2 * depth + 1, ' '), conn);
			// Iterate over the adjecent nodes of the component connection
			for (const auto& node_adjacent : conn.get_component()->get_terminals())
			{
				// Check if the connection takes back to the starting node.
				// This is optional but recommended as each node is includded in its connections
				if (node_adjacent == node_start)
					continue;
				SYMCISO_CORE_TRACE("{}Node {}", std::string(2 * depth + 2, ' '), *node_adjacent);
				// Avoid revisiting already visited nodes
				if (is_node_in_path(node_adjacent, path))
				{
					SYMCISO_CORE_TRACE("{}Already visited node {}", std::string(2 * depth + 2, ' '), *node_adjacent);
					continue;
				}
				// Recursive call to explore adjacent nodes
				if (find_path(node_adjacent, node_destination, path, depth + 1))
					return true;
			}
		}

		// Remove the current node from the path as it's not part of the successful path
		path.pop_back();

		SYMCISO_CORE_TRACE("{}Not a valid path", std::string(2 * depth + 2, ' '));
		return false;
	}


} // namespace SymCiSo
#pragma once

#include <vector>
#include <memory>
#include <string>

#include "components/impedance.h"

namespace SymCiSo
{

	class Circuit
	{
	public:
		Circuit();
		~Circuit();

		template<typename T, typename... Args>
		std::shared_ptr<T> add_component(const Args&... args)
		{
			std::shared_ptr<T> component;
			component = std::make_shared<T>(component, args...);
			m_components.emplace_back(component);
			return component;
		}
	
	public:
		std::vector<std::shared_ptr<Component>> m_components;
	};

} // namespace SymCiSo
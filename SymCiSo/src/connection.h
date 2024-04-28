#pragma once

#include <memory>

#include "core/core.h"
#include "core/log.h"

namespace SymCiSo
{

	class Connection
	{
	public:
		std::weak_ptr<Component> component;
		size_t	terminal_num;
	};

} // namespace SymCiSo
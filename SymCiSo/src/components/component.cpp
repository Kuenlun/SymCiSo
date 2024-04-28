#include "component.h"

#include "core/log.h"

namespace SymCiSo
{

	Component::~Component()
	{
		SYMCISO_CORE_TRACE("Component instance destructed: {}", get_name());
	}

} // namespace SymCiSo

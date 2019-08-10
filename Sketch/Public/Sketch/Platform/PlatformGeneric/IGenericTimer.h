#pragma once
#include "Sketch/Base/Core.h"

namespace sk
{
	class IGenericTimer
	{
	public:

		virtual UInt64 GetTime() const = 0;

	};
}

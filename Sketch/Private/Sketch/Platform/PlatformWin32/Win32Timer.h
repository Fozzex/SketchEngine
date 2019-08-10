#pragma once
#include "Sketch/Platform/PlatformGeneric/IGenericTimer.h"

namespace sk
{
	class Win32Timer : public IGenericTimer
	{
	public:

		UInt64 GetTime() const override;

	};
}

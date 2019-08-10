#pragma once
#include "Sketch/Base/Core.h"
#include "Sketch/Util/TimeStamp.h"

#include "Sketch/Platform/PlatformGeneric/IGenericTimer.h"

namespace sk
{
	class SKETCH_API Timer
	{
		static IGenericTimer* s_Timer;
	public:
		
		Timer();
		
		void Reset();
		TimeStamp GetTime() const;

	private:

		UInt64 m_StartTimeMS;

	};
}

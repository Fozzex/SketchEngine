#include "Sketch/Base/Core.h"
#include "Sketch/Util/Timer.h"

#include "Win32Timer.h"
#include "Win32CleanupApi.h"

namespace sk
{
	IGenericTimer* Timer::s_Timer = new Win32Timer();

	UInt64 Win32Timer::GetTime() const
	{
		LARGE_INTEGER counterFrequency;
		if (!QueryPerformanceFrequency(&counterFrequency))
			return 0;

		LARGE_INTEGER counterValue;
		QueryPerformanceCounter(&counterValue);

		return UInt64(counterValue.QuadPart / (counterFrequency.QuadPart / 1000000.f));
	}
}

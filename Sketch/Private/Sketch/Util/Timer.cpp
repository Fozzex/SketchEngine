#include "Sketch/Util/Timer.h"

namespace sk
{
	Timer::Timer()
	{
		this->Reset();
	}

	void Timer::Reset()
	{
		m_StartTimeMS = s_Timer->GetTime();
	}

	TimeStamp Timer::GetTime() const
	{
		return TimeStamp(s_Timer->GetTime() - m_StartTimeMS);
	}
}

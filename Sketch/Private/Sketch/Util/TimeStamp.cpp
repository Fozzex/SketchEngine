#include "Sketch/Util/TimeStamp.h"

namespace sk
{
	TimeStamp::TimeStamp(UInt64 microseconds)
		: m_Microseconds(microseconds) {}

	double TimeStamp::GetSeconds() const
	{
		return m_Microseconds / 1000000.0;
	}

	double TimeStamp::GetMilliseconds() const
	{
		return m_Microseconds / 1000.0;
	}

	UInt64 TimeStamp::GetMicroseconds() const
	{
		return m_Microseconds;
	}
}

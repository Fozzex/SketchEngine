#pragma once
#include "Sketch/Base/Core.h"

namespace sk
{
	class SKETCH_API TimeStamp
	{
	public:

		explicit TimeStamp(UInt64 microseconds);

		double GetSeconds() const;
		double GetMilliseconds() const;
		UInt64 GetMicroseconds() const;

	private:

		UInt64 m_Microseconds;

	};
}

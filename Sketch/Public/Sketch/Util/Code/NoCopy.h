#pragma once
#include "Interface.h"

namespace sk
{
	class SKETCH_API NoCopy : public Interface
	{
	public:

		NoCopy(const NoCopy& copy) = delete;
		NoCopy& operator=(const NoCopy& copy) = delete;

	};
}
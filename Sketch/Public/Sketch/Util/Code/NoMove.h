#pragma once
#include "Interface.h"

namespace sk
{
	class SKETCH_API NoMove : public Interface
	{
	public:

		NoMove(NoMove&& move) = delete;
		NoMove& operator=(NoMove&& move) = delete;

	};
}
#pragma once
#include "NoCopy.h"
#include "NoMove.h"

namespace sk
{
	class SKETCH_API Singleton 
		: public NoCopy, public NoMove
	{
	};
}
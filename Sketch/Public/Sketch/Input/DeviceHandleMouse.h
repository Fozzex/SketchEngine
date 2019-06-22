#pragma once
#include "Sketch/Base/Core.h"
#include "DeviceHandle.h"
#include "InputDeviceMouse.h"

namespace sk
{
	class SKETCH_API DeviceHandleMouse : public DeviceHandle<InputDeviceMouse>
	{
	public:

		DeviceHandleMouse(InputDeviceMouse* mouseDevice);

		void SetFlag(Mouse button, bool flag);

		void SetPositionVector(float x, float y);
		void SetScrollOffset(float x, float y);

	};
}

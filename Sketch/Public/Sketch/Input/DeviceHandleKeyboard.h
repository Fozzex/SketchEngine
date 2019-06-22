#pragma once
#include "Sketch/Base/Core.h"
#include "DeviceHandle.h"
#include "InputDeviceKeyboard.h"

namespace sk
{
	class SKETCH_API DeviceHandleKeyboard : public DeviceHandle<InputDeviceKeyboard>
	{
	public:

		DeviceHandleKeyboard(InputDeviceKeyboard* keyboardDevice);

		void SetFlag(Keyboard key, bool flag);

	};
}

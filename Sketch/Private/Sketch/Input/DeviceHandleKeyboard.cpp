#include "Sketch/Input/DeviceHandleKeyboard.h"

namespace sk
{
	DeviceHandleKeyboard::DeviceHandleKeyboard(InputDeviceKeyboard* keyboardDevice)
		: DeviceHandle(keyboardDevice) {}

	void DeviceHandleKeyboard::SetFlag(Keyboard key, bool flag)
	{
		int index = static_cast<int>(key);

		if (index >= 0 && index < InputDeviceKeyboard::GetMapSize())
			m_Device->m_Flags[index] = flag;
	}
}

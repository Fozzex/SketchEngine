#include "Sketch/Input/DeviceHandleMouse.h"

namespace sk
{
	DeviceHandleMouse::DeviceHandleMouse(InputDeviceMouse* mouseDevice)
		: DeviceHandle(mouseDevice) {}

	void DeviceHandleMouse::SetFlag(Mouse button, bool flag)
	{
		int index = static_cast<int>(button);

		if (index >= 0 && index < InputDeviceMouse::GetMapSize())
			m_Device->m_Flags[index] = flag;
	}

	void DeviceHandleMouse::SetPositionVector(float x, float y)
	{
		m_Device->m_PositionX = x;
		m_Device->m_PositionY = y;
	}

	void DeviceHandleMouse::SetScrollOffset(float x, float y)
	{
		m_Device->m_ScrollOffX = x;
		m_Device->m_ScrollOffY = y;
	}
}

#pragma once
#include "InputDevice.h"
#include "InputCodes.h"

namespace sk
{
	class InputDeviceMouse : public InputButtonDevice<Mouse>
	{
		friend class DeviceHandleMouse;
	public:

		inline float GetMouseX() const { return m_PositionX; }
		inline float GetMouseY() const { return m_PositionY; }

		inline float GetScrollOffsetX() const { return m_ScrollOffX; }
		inline float GetScrollOffsetY() const { return m_ScrollOffY; }

	private:

		float m_PositionX, m_PositionY;
		float m_ScrollOffX, m_ScrollOffY;

	};
}

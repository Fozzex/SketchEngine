#pragma once
#include "Event.h"

namespace sk
{
	class WindowCloseEvent : public Event
	{
	public:

		WindowCloseEvent() {}

	};

	class WindowResizeEvent : public Event
	{
	public:

		WindowResizeEvent(float width, float height)
			: m_Width(width), m_Height(height) {}

		inline float GetWidth() const { return m_Width; }
		inline float GetHeight() const { return m_Height; }

	private:

		float m_Width, m_Height;

	};
}

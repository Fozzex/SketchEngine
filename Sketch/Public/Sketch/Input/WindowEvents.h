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

		WindowResizeEvent(int width, int height)
			: m_Width(width), m_Height(height) {}

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

	private:

		int m_Width, m_Height;

	};
}

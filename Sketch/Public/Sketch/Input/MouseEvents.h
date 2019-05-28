#pragma once
#include "Event.h"

namespace sk
{
	class MousePressEvent : public Event
	{
	public:

		MousePressEvent(int button)
			: m_Button(button) {}

		inline int GetButton() const { return m_Button; }

	private:

		int m_Button;

	};

	class MouseReleaseEvent : public Event
	{
	public:

		MouseReleaseEvent(int button)
			: m_Button(button) {}

		inline int GetButton() const { return m_Button; }

	private:

		int m_Button;

	};

	class MouseMoveEvent : public Event
	{
	public:

		MouseMoveEvent(float x, float y)
			: m_X(x), m_Y(y) {}

		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }

	private:

		float m_X, m_Y;

	};
}

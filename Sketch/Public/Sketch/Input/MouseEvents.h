#pragma once
#include "Event.h"

namespace sk
{
	class MousePressEvent : public Event, public ModifierEvent
	{
	public:

		MousePressEvent(int button, const Modifiers& mods)
			: m_Button(button), ModifierEvent(mods) {}

		inline int GetButton() const { return m_Button; }

	private:

		int m_Button;

	};

	class MouseReleaseEvent : public Event, public ModifierEvent
	{
	public:

		MouseReleaseEvent(int button, const Modifiers& mods)
			: m_Button(button), ModifierEvent(mods) {}

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

	class ScrollEvent : public Event
	{
	public:

		ScrollEvent(float offsetX, float offsetY)
			: m_X(offsetX), m_Y(offsetY) {}
		
		inline float GetOffsetX() const { return m_X; }
		inline float GetOffsetY() const { return m_Y; }

	private:

		float m_X, m_Y;

	};

	class MouseFocusEvent : public Event
	{
	public:

		MouseFocusEvent(bool focussed)
			: m_Focussed(focussed) {}

		inline bool IsFocussed() const { return m_Focussed; }

	private:

		bool m_Focussed;

	};
}

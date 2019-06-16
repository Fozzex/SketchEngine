#pragma once
#include "Event.h"
#include "InputCodes.h"

namespace sk
{
	class KeyPressEvent : public Event, public ModifierEvent
	{
	public:

		KeyPressEvent(Keyboard keyCode, bool repeat, const Modifiers& mods)
			: m_KeyCode(keyCode), m_Repeat(repeat), ModifierEvent(mods) {}
		
		inline Keyboard GetKeyCode() const { return m_KeyCode; }
		inline bool IsRepeat() const { return m_Repeat; }

	private:

		Keyboard m_KeyCode;
		bool m_Repeat;

	};

	class KeyReleaseEvent : public Event, public ModifierEvent
	{
	public:

		KeyReleaseEvent(Keyboard keyCode, const Modifiers& mods)
			: m_KeyCode(keyCode), ModifierEvent(mods) {}

		inline Keyboard GetKeyCode() const { return m_KeyCode; }

	private:

		Keyboard m_KeyCode;

	};

	class TypeEvent : public Event
	{
	public:

		TypeEvent(char key)
			: m_Key(key) {}

		inline char GetKey() const { return m_Key; }

	private:

		char m_Key;

	};
}

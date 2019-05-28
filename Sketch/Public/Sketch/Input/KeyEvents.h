#pragma once
#include "Event.h"

namespace sk
{
	class KeyPressEvent : public Event
	{
	public:

		KeyPressEvent(int keyCode, int count)
			: m_KeyCode(keyCode), m_Count(count) {}
		
		inline int GetKeyCode() const { return m_KeyCode; }
		inline int GetCount() const { return m_Count; }

	private:

		int m_KeyCode, m_Count;

	};

	class KeyReleaseEvent : public Event
	{
	public:

		KeyReleaseEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		inline int GetKeyCode() const { return m_KeyCode; }

	private:

		int m_KeyCode;

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

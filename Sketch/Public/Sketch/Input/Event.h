#pragma once

namespace sk
{
	class Event
	{
	public:

		Event() {}
		virtual ~Event() {}

	};

	class ModifierEvent
	{
	public:

		struct Modifiers
		{
			bool shift, ctrl, alt, super;
		};

	public:

		ModifierEvent(const Modifiers& mods)
			: m_Modifiers(mods) {}

		inline bool IsModShift() const { return m_Modifiers.shift; }
		inline bool IsModControl() const { return m_Modifiers.ctrl; }
		inline bool IsModAlt() const { return m_Modifiers.alt; }
		inline bool IsModSuper() const { return m_Modifiers.super; }

	private:

		Modifiers m_Modifiers;

	};
}

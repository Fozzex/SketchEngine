#pragma once
#include <array>

namespace sk
{
	class InputDevice 
	{
	public:
		virtual ~InputDevice() {}
	};

	template<class InputEnum>
	class InputButtonDevice : public InputDevice
	{
		static constexpr int s_EnumSize = static_cast<int>(InputEnum::Count);
	public:

		virtual ~InputButtonDevice() {}

		virtual bool IsPressed(InputEnum element) const
		{
			unsigned int index = static_cast<unsigned int>(element);

			if (index < s_EnumSize)
				return m_Flags[index];

			return false;
		}

		static constexpr int GetMapSize()
		{
			return s_EnumSize;
		}

	protected:

		std::array<bool, s_EnumSize> m_Flags = { false };

	};
}

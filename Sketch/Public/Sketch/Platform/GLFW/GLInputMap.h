#pragma once
#include <unordered_map>
#include <GLFW/glfw3.h>

#include "Sketch/Input/InputCodes.h"

namespace sk
{
	template<class InputEnum>
	class GLInputMap
	{
	public:

		static InputEnum GetGeneric(int code)
		{
			if (!s_Map.empty())
			{
				auto mapIt = s_Map.find(code);
				if (mapIt != s_Map.end())
				{
					return mapIt->second;
				}
			}

			return InputEnum::Unknown;
		}

	private:

		static std::unordered_map<int, InputEnum> s_Map;

	};
}

#pragma once
#include "Sketch/Base/Core.h"
#include "Sketch/Base/Window.h"

namespace sk
{
	class SKETCH_API Input
	{
		friend class Window;
	public:
		
		static bool IsKeyPressed(Keyboard key);
		static bool IsButtonPressed(Mouse button);

		static std::pair<float, float> GetMousePosition();
		static std::pair<float, float> GetScrollOffset();

		static float GetMouseX();
		static float GetMouseY();

		static float GetScrollOffsetX();
		static float GetScrollOffsetY();

	private:

		static const Window* s_ActiveWindow;

	};
}

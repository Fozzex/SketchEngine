#include "Sketch/Input/Input.h"

// TODO: Check if window is the current active window.
namespace sk
{
	const Window* Input::s_ActiveWindow = nullptr;
	
	bool Input::IsKeyPressed(Keyboard key)
	{
		if (s_ActiveWindow)
			return s_ActiveWindow->GetKeyboard()->IsPressed(key);

		return false;
	}

	bool Input::IsButtonPressed(Mouse button)
	{
		if (s_ActiveWindow)
			return s_ActiveWindow->GetMouse()->IsPressed(button);

		return false;
	}

	float Input::GetMouseX()
	{
		if (s_ActiveWindow)
			return s_ActiveWindow->GetMouse()->GetMouseX();

		return 0.0f;
	}

	float Input::GetMouseY()
	{
		if (s_ActiveWindow)
			return s_ActiveWindow->GetMouse()->GetMouseY();

		return 0.0f;
	}

	float Input::GetScrollOffsetX()
	{
		if (s_ActiveWindow)
			return s_ActiveWindow->GetMouse()->GetScrollOffsetX();

		return 0.0f;
	}

	float Input::GetScrollOffsetY()
	{
		if (s_ActiveWindow)
			return s_ActiveWindow->GetMouse()->GetScrollOffsetY();

		return 0.0f;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		if (s_ActiveWindow)
		{
			auto* mouse = s_ActiveWindow->GetMouse();

			return { mouse->GetMouseX(), mouse->GetMouseY() };
		}

		return { 0.0f, 0.0f };
	}

	std::pair<float, float> Input::GetScrollOffset()
	{
		if (s_ActiveWindow)
		{
			auto* mouse = s_ActiveWindow->GetMouse();

			return { mouse->GetScrollOffsetX(), mouse->GetScrollOffsetY() };
		}

		return { 0.0f, 0.0f };
	}
}

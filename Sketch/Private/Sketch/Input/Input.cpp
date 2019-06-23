#include "Sketch/Input/Input.h"

// TODO: Check if window is the current active window.
namespace sk
{
	const Window* Input::m_WindowHandle = nullptr;

	void Input::AttachWindow(const Window* windowHandle)
	{
		m_WindowHandle = windowHandle;
	}

	
	bool Input::IsKeyPressed(Keyboard key)
	{
		if (m_WindowHandle)
			return m_WindowHandle->GetKeyboard()->IsPressed(key);

		return false;
	}

	bool Input::IsButtonPressed(Mouse button)
	{
		if (m_WindowHandle)
			return m_WindowHandle->GetMouse()->IsPressed(button);

		return false;
	}

	float Input::GetMouseX()
	{
		if (m_WindowHandle)
			return m_WindowHandle->GetMouse()->GetMouseX();

		return 0.0f;
	}

	float Input::GetMouseY()
	{
		if (m_WindowHandle)
			return m_WindowHandle->GetMouse()->GetMouseY();

		return 0.0f;
	}

	float Input::GetScrollOffsetX()
	{
		if (m_WindowHandle)
			return m_WindowHandle->GetMouse()->GetScrollOffsetX();

		return 0.0f;
	}

	float Input::GetScrollOffsetY()
	{
		if (m_WindowHandle)
			return m_WindowHandle->GetMouse()->GetScrollOffsetY();

		return 0.0f;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		if (m_WindowHandle)
		{
			auto* mouse = m_WindowHandle->GetMouse();

			return { mouse->GetMouseX(), mouse->GetMouseY() };
		}

		return { 0.0f, 0.0f };
	}

	std::pair<float, float> Input::GetScrollOffset()
	{
		if (m_WindowHandle)
		{
			auto* mouse = m_WindowHandle->GetMouse();

			return { mouse->GetScrollOffsetX(), mouse->GetScrollOffsetY() };
		}

		return { 0.0f, 0.0f };
	}
}

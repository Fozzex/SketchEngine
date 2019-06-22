#include "Sketch/Base/Window.h"

namespace sk
{
	Window::Window(int width, int height, const std::string& title)
		: m_Width(width), m_Height(height), m_Title(title)
		, m_KeyboardHandle(&m_KeyboardDevice)
		, m_MouseHandle(&m_MouseDevice)
	{
	}

	void Window::SetWidth(int width)
	{
		m_Width = width;
		this->SetWindowSize(m_Width, m_Height);
	}

	void Window::SetHeight(int height)
	{
		m_Height = height;
		this->SetWindowSize(m_Width, m_Height);
	}

	void Window::SetSize(int width, int height)
	{
		m_Width = width;
		m_Height = height;
		this->SetWindowSize(m_Width, m_Height);
	}

	void Window::SetTitle(const std::string& title)
	{
		m_Title = title;
		this->SetWindowTitle(m_Title);
	}

	void Window::SetVerticalSync(bool enable)
	{
		m_VSync = enable;
		this->SetWindowVSync(enable);
	}

	void Window::SetDispatcher(EventDispatcher* dispatcher)
	{
		m_Dispatcher = dispatcher;
		this->InitEventCallbacks();
	}
}

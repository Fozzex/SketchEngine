#include "Sketch/Base/Window.h"

namespace sk
{
	Window::Window(int width, int height, const std::string& title)
		: m_Width(width), m_Height(height), m_Title(title)
	{
		m_WindowImpl = IGenericWindow::Create(m_Width, m_Height, m_Title, this);
	}

	Window::~Window()
	{
		delete m_WindowImpl;
	}

	void Window::SetWidth(int width)
	{
		m_Width = width;
		m_WindowImpl->SetSize(m_Width, m_Height);
	}

	void Window::SetHeight(int height)
	{
		m_Height = height;
		m_WindowImpl->SetSize(m_Width, m_Height);
	}

	void Window::SetSize(int width, int height)
	{
		m_Width = width;
		m_Height = height;
		m_WindowImpl->SetSize(m_Width, m_Height);
	}

	void Window::SetTitle(const std::string& title)
	{
		m_Title = title;
		m_WindowImpl->SetTitle(m_Title);
	}

	void Window::SetVerticalSync(bool enable)
	{
		m_VSync = enable;
		m_WindowImpl->SetVSync(m_VSync);
	}
}

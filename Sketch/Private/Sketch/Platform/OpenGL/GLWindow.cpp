#include "Sketch/Platform/OpenGL/GLWindow.h"

namespace sk
{
	Window* Window::Create(int width, int height, const std::string& title)
	{
		return new GLWindow(width, height, title);
	}

	GLWindow::GLWindow(int width, int height, const std::string& title)
		: Window(width, height, title)
	{
		this->Init(width, height, title);
	}

	void GLWindow::Init(int width, int height, const std::string& title)
	{
		int glfwResult = glfwInit();
		assert(glfwResult);
		
		m_RawWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	}

	bool GLWindow::Closed()
	{
		return glfwWindowShouldClose(m_RawWindow);
	}

	void GLWindow::SwapBuffers()
	{
		glfwSwapBuffers(m_RawWindow);
		glfwPollEvents();
	}

	void* GLWindow::GetRaw() const
	{
		return static_cast<void*>(m_RawWindow);
	}

	void GLWindow::SetWindowSize(int width, int height)
	{
		glfwSetWindowSize(m_RawWindow, width, height);
	}

	void GLWindow::SetWindowTitle(const std::string& title)
	{
		glfwSetWindowTitle(m_RawWindow, title.c_str());
	}

	void GLWindow::SetWindowVSync(bool enable)
	{
		glfwSwapInterval(enable ? 1 : 0);
	}
}
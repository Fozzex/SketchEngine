#include "Sketch/Platform/OpenGL/GLWindow.h"

#include "Sketch/Input/KeyEvents.h"
#include "Sketch/Input/MouseEvents.h"
#include "Sketch/Input/WindowEvents.h"

namespace sk
{
	Window* Window::Create(int width, int height, const std::string& title)
	{
		return new GLWindow(width, height, title);
	}

	GLWindow::GLWindow(int width, int height, const std::string& title)
		: Window(width, height, title)
	{
		int glfwResult = glfwInit();
		assert(glfwResult);

		m_RawWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(m_RawWindow, this);
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

	void GLWindow::InitEventCallbacks()
	{
		glfwSetKeyCallback(m_RawWindow, KeyCallback);
		glfwSetCharCallback(m_RawWindow, TypeCallback);
		glfwSetCursorPosCallback(m_RawWindow, CursorMoveCallback);
		glfwSetMouseButtonCallback(m_RawWindow, MouseButtonCallback);
		glfwSetCursorEnterCallback(m_RawWindow, CursorEnterCallback);
		glfwSetScrollCallback(m_RawWindow, ScrollCallback);
		glfwSetWindowSizeCallback(m_RawWindow, WindowResizeCallback);
		glfwSetWindowCloseCallback(m_RawWindow, WindowCloseCallback);
	}

	void GLWindow::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto glWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));
		
		ModifierEvent::Modifiers modifiers;
		modifiers.shift = mods & GLFW_MOD_SHIFT;
		modifiers.ctrl = mods & GLFW_MOD_CONTROL;
		modifiers.alt = mods & GLFW_MOD_ALT;
		modifiers.super = mods & GLFW_MOD_SUPER;

		bool repeat = false;

		switch (action)
		{
			{
			case GLFW_REPEAT:
				repeat = true;
			case GLFW_PRESS:
				KeyPressEvent evnt(key, repeat, modifiers);
				glWindow->m_Dispatcher->Dispatch<KeyPressEvent>(evnt);
				break;
			}

			case GLFW_RELEASE:
				KeyReleaseEvent evnt(key, modifiers);
				glWindow->m_Dispatcher->Dispatch<KeyReleaseEvent>(evnt);
				break;
		}
	}

	void GLWindow::TypeCallback(GLFWwindow* window, unsigned int codepoint)
	{
		auto glWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

		TypeEvent evnt((char)codepoint);
		glWindow->m_Dispatcher->Dispatch<TypeEvent>(evnt);
	}

	void GLWindow::CursorMoveCallback(GLFWwindow* window, double x, double y)
	{
		auto glWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

		MouseMoveEvent evnt((float)x, (float)y);
		glWindow->m_Dispatcher->Dispatch<MouseMoveEvent>(evnt);
	}

	void GLWindow::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		auto glWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

		ModifierEvent::Modifiers modifiers;
		modifiers.shift = mods & GLFW_MOD_SHIFT;
		modifiers.ctrl = mods & GLFW_MOD_CONTROL;
		modifiers.alt = mods & GLFW_MOD_ALT;
		modifiers.super = mods & GLFW_MOD_SUPER;

		switch (action)
		{
			case GLFW_PRESS:
			{
				MousePressEvent evnt(button, modifiers);
				glWindow->m_Dispatcher->Dispatch<MousePressEvent>(evnt);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseReleaseEvent evnt(button, modifiers);
				glWindow->m_Dispatcher->Dispatch<MouseReleaseEvent>(evnt);
				break;
			}
		}
	}

	void GLWindow::CursorEnterCallback(GLFWwindow* window, int entered)
	{
		auto glWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

		MouseFocusEvent evnt((bool)entered);
		glWindow->m_Dispatcher->Dispatch<MouseFocusEvent>(evnt);
	}

	void GLWindow::ScrollCallback(GLFWwindow* window, double x, double y)
	{
		auto glWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

		ScrollEvent evnt((float)x, (float)y);
		glWindow->m_Dispatcher->Dispatch<ScrollEvent>(evnt);
	}

	void GLWindow::WindowResizeCallback(GLFWwindow* window, int width, int height)
	{
		auto glWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

		WindowResizeEvent evnt(width, height);
		glWindow->m_Dispatcher->Dispatch<WindowResizeEvent>(evnt);
	}

	void GLWindow::WindowCloseCallback(GLFWwindow* window)
	{
		auto glWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

		WindowCloseEvent evnt;
		glWindow->m_Dispatcher->Dispatch<WindowCloseEvent>(evnt);
	}
}

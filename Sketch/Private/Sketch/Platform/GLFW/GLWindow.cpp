#include "GLWindow.h"
#include <assert.h>

#include "Sketch/Input/EventKeyboard.h"
#include "Sketch/Input/EventMouse.h"
#include "Sketch/Input/EventWindow.h"
#include "Sketch/Base/Window.h"
#include "GLInputMap.h"

namespace sk
{
	GLWindow::GLWindow(int width, int height, const std::string& title, Window* wrapper)
	{
		int glfwResult = glfwInit();
		assert(glfwResult);

		m_RawWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(m_RawWindow, wrapper);

		glfwSetKeyCallback(m_RawWindow, KeyCallback);
		glfwSetCharCallback(m_RawWindow, TypeCallback);
		glfwSetCursorPosCallback(m_RawWindow, CursorMoveCallback);
		glfwSetMouseButtonCallback(m_RawWindow, MouseButtonCallback);
		glfwSetCursorEnterCallback(m_RawWindow, CursorEnterCallback);
		glfwSetScrollCallback(m_RawWindow, ScrollCallback);
		glfwSetWindowSizeCallback(m_RawWindow, WindowResizeCallback);
		glfwSetWindowCloseCallback(m_RawWindow, WindowCloseCallback);
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

	void GLWindow::SetSize(int width, int height)
	{
		glfwSetWindowSize(m_RawWindow, width, height);
	}

	void GLWindow::SetTitle(const std::string& title)
	{
		glfwSetWindowTitle(m_RawWindow, title.c_str());
	}

	void GLWindow::SetVSync(bool enable)
	{
		glfwSwapInterval(enable ? 1 : 0);
	}

	void GLWindow::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto glWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
		
		if (glWindow->GetDispatcher())
		{
			ModifierEvent::Modifiers modifiers;
			modifiers.shift = mods & GLFW_MOD_SHIFT;
			modifiers.ctrl = mods & GLFW_MOD_CONTROL;
			modifiers.alt = mods & GLFW_MOD_ALT;
			modifiers.super = mods & GLFW_MOD_SUPER;

			Keyboard genericKey = GLInputMap<Keyboard>::GetGeneric(key);

			bool repeat = false;

			switch (action)
			{
				{
				case GLFW_REPEAT:
					repeat = true;
				case GLFW_PRESS:
					KeyPressEvent evnt(genericKey, repeat, modifiers);
					glWindow->GetDispatcher()->Dispatch<KeyPressEvent>(evnt);
					break;
				}

				case GLFW_RELEASE:
					KeyReleaseEvent evnt(GLInputMap<Keyboard>::GetGeneric(key), modifiers);
					glWindow->GetDispatcher()->Dispatch<KeyReleaseEvent>(evnt);
					break;
			}
		}
	}

	void GLWindow::TypeCallback(GLFWwindow* window, unsigned int codepoint)
	{
		auto glWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (glWindow->GetDispatcher())
		{
			TypeEvent evnt((char)codepoint);
			glWindow->GetDispatcher()->Dispatch<TypeEvent>(evnt);
		}
	}

	void GLWindow::CursorMoveCallback(GLFWwindow* window, double x, double y)
	{
		auto glWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (glWindow->GetDispatcher())
		{
			MouseMoveEvent evnt((float)x, (float)y);
			glWindow->GetDispatcher()->Dispatch<MouseMoveEvent>(evnt);
		}
	}

	void GLWindow::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		auto glWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (glWindow->GetDispatcher())
		{
			ModifierEvent::Modifiers modifiers;
			modifiers.shift = mods & GLFW_MOD_SHIFT;
			modifiers.ctrl = mods & GLFW_MOD_CONTROL;
			modifiers.alt = mods & GLFW_MOD_ALT;
			modifiers.super = mods & GLFW_MOD_SUPER;

			Mouse genericButton = GLInputMap<Mouse>::GetGeneric(button);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MousePressEvent evnt(genericButton, modifiers);
					glWindow->GetDispatcher()->Dispatch<MousePressEvent>(evnt);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseReleaseEvent evnt(genericButton, modifiers);
					glWindow->GetDispatcher()->Dispatch<MouseReleaseEvent>(evnt);
					break;
				}
			}
		}
	}

	void GLWindow::CursorEnterCallback(GLFWwindow* window, int entered)
	{
		auto glWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (glWindow->GetDispatcher())
		{
			MouseFocusEvent evnt((bool)entered);
			glWindow->GetDispatcher()->Dispatch<MouseFocusEvent>(evnt);
		}
	}

	void GLWindow::ScrollCallback(GLFWwindow* window, double x, double y)
	{
		auto glWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (glWindow->GetDispatcher())
		{
			ScrollEvent evnt((float)x, (float)y);
			glWindow->GetDispatcher()->Dispatch<ScrollEvent>(evnt);
		}
	}

	void GLWindow::WindowResizeCallback(GLFWwindow* window, int width, int height)
	{
		auto glWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (glWindow->GetDispatcher())
		{
			WindowResizeEvent evnt(width, height);
			glWindow->GetDispatcher()->Dispatch<WindowResizeEvent>(evnt);
		}
	}

	void GLWindow::WindowCloseCallback(GLFWwindow* window)
	{
		auto glWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (glWindow->GetDispatcher())
		{
			WindowCloseEvent evnt;
			glWindow->GetDispatcher()->Dispatch<WindowCloseEvent>(evnt);
		}
	}

	IGenericWindow* IGenericWindow::Create(int width, int height, const std::string& title, Window* wrapper)
	{
		return new GLWindow(width, height, std::move(title), wrapper);
	}
}

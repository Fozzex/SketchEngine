#pragma once
#include <assert.h>

#include "Sketch/Base/Window.h"

#include <GLFW/glfw3.h>

namespace sk
{
	class SKETCH_API GLWindow : public Window
	{
	public:

		GLWindow(int width, int height, const std::string& title);

		bool Closed() override;
		void SwapBuffers() override;

		void* GetRaw() const override;

	protected:

		void SetWindowSize(int width, int height) override;
		void SetWindowTitle(const std::string& title) override;
		void SetWindowVSync(bool enable) override;

		void InitEventCallbacks() override;

	private:

		GLFWwindow* m_RawWindow;

	private:

		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void TypeCallback(GLFWwindow* window, unsigned int codepoint);
		static void CursorMoveCallback(GLFWwindow* window, double x, double y);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void CursorEnterCallback(GLFWwindow* window, int entered);
		static void ScrollCallback(GLFWwindow* window, double x, double y);
		static void WindowResizeCallback(GLFWwindow* window, int width, int height);
		static void WindowCloseCallback(GLFWwindow* window);
		static void WindowFocusCallback(GLFWwindow* window, int focussed);

	};
}

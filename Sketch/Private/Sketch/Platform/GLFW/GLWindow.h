#pragma once
#include "Sketch/Base/Core.h"
#include "Sketch/Platform/PlatformGeneric/IGenericWindow.h"

#include <string>

struct GLFWwindow;

namespace sk
{
	class Window;

	class GLWindow : public IGenericWindow
	{
	public:

		GLWindow(int width, int height, const std::string& title, Window* wrapper);

		bool Closed() override;
		void SwapBuffers() override;

		void* GetRaw() const override;

		void SetSize(int width, int height) override;
		void SetTitle(const std::string& title) override;
		void SetVSync(bool enable) override;

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

	};
}

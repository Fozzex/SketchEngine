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

	private:

		void Init(int width, int height, const std::string& title);

	private:

		GLFWwindow* m_RawWindow;

	};
}
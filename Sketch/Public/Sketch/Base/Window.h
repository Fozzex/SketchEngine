#pragma once
#include <string>

#include "Core.h"
#include "Sketch/Input/EventDispatcher.h"

#include "Sketch/Platform/PlatformGeneric/IGenericWindow.h"

namespace sk
{
	class SKETCH_API Window
	{
	public:

		Window(int width, int height, const std::string& title);
		virtual ~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;

		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

		void SetWidth(int width);
		void SetHeight(int height);
		void SetSize(int width, int height);

		void SetTitle(const std::string& title);
		void SetVerticalSync(bool enable);

		inline bool Closed() { return m_WindowImpl->Closed(); }
		inline void SwapBuffers() { m_WindowImpl->SwapBuffers(); }

		inline bool IsFocussed() const { return m_WindowImpl->IsFocussed(); }

		inline int GetWidth() const { return m_Width; };
		inline int GetHeight() const { return m_Height; };

		inline std::string GetTitle() const { return m_Title; }
		inline bool GetVSync() const { return m_VSync; }

		inline EventDispatcher* GetDispatcher() { return m_WindowImpl->GetDispatcher(); }
		inline void SetDispatcher(EventDispatcher* dispatcher) { m_WindowImpl->SetDispatcher(dispatcher); }

	private:

		IGenericWindow* m_WindowImpl;

		int m_Width, m_Height;

		std::string m_Title;
		bool m_VSync = false;

	};
}

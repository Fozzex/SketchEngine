#pragma once
#include "Sketch/Base/Core.h"

#include <string>


namespace sk
{
	class EventDispatcher;
	class Window;

	class IGenericWindow
	{
	public:

		IGenericWindow() = default;

		IGenericWindow(const IGenericWindow&) = delete;
		IGenericWindow(IGenericWindow&&) = delete;

		IGenericWindow& operator=(const IGenericWindow&) = delete;
		IGenericWindow& operator=(IGenericWindow&&) = delete;

		virtual bool Closed() = 0;
		virtual void SwapBuffers() = 0;

		virtual void* GetRaw() const = 0;

		virtual void SetSize(int width, int height) = 0;
		virtual void SetTitle(const std::string& title) = 0;
		virtual void SetVSync(bool enable) = 0;

		inline bool IsFocussed() const { return m_IsFocussed; }

		inline EventDispatcher* GetDispatcher() { return m_Dispatcher; }
		inline void SetDispatcher(EventDispatcher* dispatcher) { m_Dispatcher = dispatcher; }

		static IGenericWindow* Create(int, int, const std::string&, Window*);

	protected:

		bool m_IsFocussed = false;
		EventDispatcher* m_Dispatcher = nullptr;

	};
}

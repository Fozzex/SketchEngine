#pragma once
#include <string>

#include "Core.h"
#include "Sketch/Input/EventDispatcher.h"
#include "Sketch/Input/InputDeviceMouse.h"
#include "Sketch/Input/InputDeviceKeyboard.h"

#include "Sketch/Input/DeviceHandleKeyboard.h"
#include "Sketch/Input/DeviceHandleMouse.h"

namespace sk
{
	class SKETCH_API Window
	{
	public:

		Window(int width, int height, const std::string& title);
		virtual ~Window() {}

		virtual bool Closed() = 0;
		virtual void SwapBuffers() = 0;

		void SetWidth(int width);
		void SetHeight(int height);
		void SetSize(int width, int height);

		void SetTitle(const std::string& title);
		void SetVerticalSync(bool enable);

		inline int GetWidth() const { return m_Width; };
		inline int GetHeight() const { return m_Height; };

		inline std::string GetTitle() const { return m_Title; }
		inline bool GetVSync() const { return m_VSync; }

		inline bool IsFocussed() const { return m_ActiveWindowFlag; }

		inline void SetDispatcher(EventDispatcher* dispatcher);

		inline const InputDeviceKeyboard* GetKeyboard() const { return &m_KeyboardDevice; }
		inline const InputDeviceMouse* GetMouse() const { return &m_MouseDevice; }

		virtual void* GetRaw() const = 0;

		static Window* Create(int width = 1280, int height = 720, const std::string& title = "Sketch");

	protected:

		virtual void SetWindowSize(int width, int height) = 0;
		virtual void SetWindowTitle(const std::string& title) = 0;
		virtual void SetWindowVSync(bool enable) = 0;

		virtual void InitEventCallbacks() = 0;

		static void SetActiveWindow(Window* window);

	protected:

		EventDispatcher* m_Dispatcher = nullptr;

		DeviceHandleKeyboard m_KeyboardHandle;
		DeviceHandleMouse m_MouseHandle;

		bool m_ActiveWindowFlag = false;

	private:

		int m_Width, m_Height;

		std::string m_Title;
		bool m_VSync = false;

		InputDeviceKeyboard m_KeyboardDevice;
		InputDeviceMouse m_MouseDevice;

	};
}

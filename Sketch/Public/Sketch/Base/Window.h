#pragma once
#include <string>

#include "Core.h"
#include "Sketch/Util/Code/Interface.h"

namespace sk
{
	class SKETCH_API Window : public Interface
	{
	public:

		Window(int width, int height, const std::string& title);

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

		virtual void* GetRaw() const = 0;

		static Window* Create(int width = 1280, int height = 720, const std::string& title = "Sketch");

	protected:

		virtual void SetWindowSize(int width, int height) = 0;
		virtual void SetWindowTitle(const std::string& title) = 0;
		virtual void SetWindowVSync(bool enable) = 0;

	private:

		int m_Width, m_Height;

		std::string m_Title;
		bool m_VSync = false;

	};
}
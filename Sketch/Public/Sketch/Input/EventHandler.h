#pragma once
#include <functional>

#include "Event.h"

namespace sk
{
	template<class TEvent>
	class EventHandler
	{
	public:

		EventHandler(const std::function<bool(TEvent&)>& handler)
			: m_Handler(handler) {}

		bool operator()(TEvent& e) { return m_Handler(e); }

	private:

		std::function<bool(TEvent&)> m_Handler;

	};
}

#pragma once
#include <unordered_map>
#include <typeindex>

#include "Event.h"
#include "EventHandler.h"

namespace sk
{
	class EventDispatcher
	{
	public:

		template<class TEvent>
		bool Dispatch(TEvent& evnt)
		{
			auto handlerIt = m_Handlers.find(typeid(TEvent));
			if (handlerIt != m_Handlers.end())
			{
				auto handler = *reinterpret_cast<EventHandler<TEvent>*>(handlerIt->second);
				return handler(evnt);
			}

			return false;
		}

		template<class TEvent>
		void AddListener(EventHandler<TEvent>* handler)
		{
			m_Handlers.emplace(typeid(TEvent), reinterpret_cast<EventHandler<Event>*>(handler));
		}

	private:

		std::unordered_map<std::type_index, EventHandler<Event>*> m_Handlers = {};

	};
}

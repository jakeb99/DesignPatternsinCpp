#include "EventDispatcher.h"
#include <iostream>

void EventDispatcher::PublishEvent(const Event& e)
{
	std::cout << "publishing event" << std::endl;
	for (auto& handler : m_EventHandlers)
	{
		std::cout << "in handle loop" << std::endl;
		handler(e);
	}
}

void EventDispatcher::SubscribeToEvent(std::function<void(const Event&)> callback)
{
	std::cout << "subbing to event" << std::endl;
	m_EventHandlers.push_back(callback);
}

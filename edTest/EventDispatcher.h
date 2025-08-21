#pragma once
#include <string>
#include "Event.h"
#include <functional>
#include <vector>

class EventDispatcher
{
public:
	static EventDispatcher& GetInstance()
	{
		static EventDispatcher instance;
		return instance;
	}

	EventDispatcher(const EventDispatcher&) = delete;
	EventDispatcher& operator=(const EventDispatcher&) = delete;

	void PublishEvent(const Event& e);
	void SubscribeToEvent(std::function<void(const Event&)> callback);
private:
	EventDispatcher() = default;
	std::vector<std::function<void(const Event&)>> m_EventHandlers;
};
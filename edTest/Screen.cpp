#include "Screen.h"

Screen::Screen()
{
}

void Screen::DoScreenStuff()
{
	// subscribe to event
	EventDispatcher::GetInstance().SubscribeToEvent([this](const Event& e) {
		this->OnEvent(e);
	});
}

void Screen::OnEvent(const Event& e)
{
	// handle the event
	std::cout << e.Name << " " << e.Data << std::endl;
}

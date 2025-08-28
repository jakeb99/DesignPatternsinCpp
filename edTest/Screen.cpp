#include "Screen.h"
#include "Log.h"

Screen::Screen()
{
}

void Screen::DoScreenStuff()
{
	// subscribe to events
	EventDispatcher::GetInstance().SubscribeToEvent([this](const Event& e) {
		Log::Debug(e.type()); 
		Log::Error(e.type()); 
		if (e.type() == ButtonEvent::descriptor)
		{
			const ButtonEvent& btnEvent = static_cast<const ButtonEvent&>(e);
			this->OnButtonEvent(btnEvent);
		}
		else if (e.type() == SliderEvent::descriptor)
		{
			const SliderEvent& sliderEvent = static_cast<const SliderEvent&>(e);
			this->OnSliderEvent(sliderEvent);
		}
		else
		{
			this->OnEvent(e);
		}
	});	
}

void Screen::OnEvent(const Event& e)
{
	// handle the event
	std::cout << e.type() << std::endl;
}

void Screen::OnButtonEvent(const ButtonEvent& e)
{
	std::cout << e.Name << std::endl;
}

void Screen::OnSliderEvent(const SliderEvent& e)
{
	std::cout << e.Name << " data: " << e.Value << std::endl;
}

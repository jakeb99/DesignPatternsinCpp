#pragma once
#include "Event.h"
#include "EventDispatcher.h"
#include <iostream>

class Screen
{
public:
	Screen();
	void DoScreenStuff();
private:
	void OnEvent(const Event& e);
	void OnButtonEvent(const ButtonEvent& btnEvent);
	void OnSliderEvent(const SliderEvent& btnEvent);
};


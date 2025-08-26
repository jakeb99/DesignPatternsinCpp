#include "Event.h"

Event::~Event()
{
}

ButtonEvent::ButtonEvent(const char* name) : Name(name)
{
}

ButtonEvent::~ButtonEvent()
{
}

const char* ButtonEvent::type() const
{
	return descriptor;
}

SliderEvent::SliderEvent(const char* name, const float val) : Name(name), Value(val)
{
}

SliderEvent::~SliderEvent()
{
}

const char* SliderEvent::type() const
{
	return descriptor;
}

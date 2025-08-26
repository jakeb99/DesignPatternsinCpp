#pragma once
#include <string>

class Event {
public:
	virtual~ Event();
	using DescriptorType = const char*;
	virtual DescriptorType type() const = 0;		// each derived class will supply a unique type
};

class ButtonEvent : public Event {
public:
	ButtonEvent(const char* name);
	virtual ~ButtonEvent();

	static constexpr DescriptorType descriptor = "ButtonEvent";

	virtual DescriptorType type() const;

	const char* Name;
};

class SliderEvent : public Event {
public:
	SliderEvent(const char* name, const float val);
	virtual ~SliderEvent();

	static constexpr DescriptorType descriptor = "SliderEvent";

	virtual DescriptorType type() const;

	const char* Name;
	const float Value;
};
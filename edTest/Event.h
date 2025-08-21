#pragma once
#include <string>

class Event
{
public:
	std::string Name;
	int Data;

	Event(std::string name, int data);
};


#include <iostream>
#include "Screen.h"
#include "UIWindow.h"
#include "EventDispatcher.h"

int main()
{
	std::cout << "Hello world!" << std::endl;

	EventDispatcher& dispatcher = EventDispatcher::GetInstance();

	Screen screen;
	UIWindow uiwindow;

	screen.DoScreenStuff();
	uiwindow.DoUIThings();
}
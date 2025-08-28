#include <iostream>
#include "Screen.h"
#include "UIWindow.h"
#include "EventDispatcher.h"
#include "Log.h"

int main()
{
	std::cout << "Hello world!" << std::endl;

	Log::Error("static");
	Log::Warn("static");
	Log::Info("static");
	Log::Debug("static");

	EventDispatcher& dispatcher = EventDispatcher::GetInstance();

	Screen screen;
	UIWindow uiwindow;

	screen.DoScreenStuff();
	uiwindow.DoUIThings();
}
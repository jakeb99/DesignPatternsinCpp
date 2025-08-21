#include "UIWindow.h"
#include "Event.h"
#include <iostream>

UIWindow::UIWindow()
{
}

void UIWindow::DoUIThings()
{
	// create event
	Event e("UIEvent", 12);

	// pulish an event
	EventDispatcher::GetInstance().PublishEvent(e);
}

#include "UIWindow.h"
#include "Event.h"
#include <iostream>

UIWindow::UIWindow()
{
}

void UIWindow::DoUIThings()
{
	// create event
	//Event e("UIEvent", 12);
	//ButtonEvent bE("CreateLight");
	SliderEvent e("Pos x", 10.2f);

	// pulish an event
	EventDispatcher::GetInstance().PublishEvent(e);
}

#include <iostream>
#include <Sketch/Sketch.h>

static sk::Logger g_Logger("C:/dev-2019/SketchEngine/Game/Logs/SetupLogs.txt");

bool OnKeyPressEvent(sk::KeyPressEvent& e)
{
	g_Logger.Log("Key press handled: ", e.GetKeyCode());

	return true;
}

bool OnMouseMoveEvent(sk::MouseMoveEvent& e)
{
	return true;
}

int main()
{
	sk::Window window(1280, 720, "Sketch");
	g_Logger.Log("Window created");
	window.SetVerticalSync(true);

	sk::EventDispatcher dispatcher;
	window.SetDispatcher(&dispatcher);

	sk::EventHandler<sk::KeyPressEvent> keyPressHandler(OnKeyPressEvent);
	dispatcher.AddListener(&keyPressHandler);

	sk::EventHandler<sk::MouseMoveEvent> mouseMoveHandler(OnMouseMoveEvent);
	dispatcher.AddListener(&mouseMoveHandler);

	while (!window.Closed())
	{
		window.SwapBuffers();
	}
}

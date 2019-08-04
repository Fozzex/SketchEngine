#include <iostream>
#include <Sketch/Sketch.h>

static sk::Logger g_Logger("C:/dev-2019/SketchEngine/Game/Logs/SetupLogs.txt");

bool OnKeyPressEvent(sk::KeyPressEvent& e)
{
	g_Logger.Log("Key press handled: ", e.GetKeyCode());

	return true;
}

int main()
{
	sk::Window* window = sk::Window::Create();
	g_Logger.Log("Window created");
	window->SetVerticalSync(true);

	sk::EventDispatcher dispatcher;
	window->SetDispatcher(&dispatcher);

	sk::EventHandler<sk::KeyPressEvent> keyPressHandler(OnKeyPressEvent);
	dispatcher.AddListener(&keyPressHandler);

	while (!window->Closed())
	{
		window->SwapBuffers();
	}

	delete window;
}

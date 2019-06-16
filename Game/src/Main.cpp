#include <iostream>
#include <Sketch/Sketch.h>
#include <Sketch/Input/InputDeviceMouse.h>

bool OnKeyPressEvent(sk::KeyPressEvent& e)
{
	std::cout << static_cast<int>(e.GetKeyCode()) << std::endl;
	return true;
}

int main()
{
	sk::Window* window = sk::Window::Create();
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

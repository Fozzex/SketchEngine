#include <iostream>
#include <Sketch/Sketch.h>

bool OnKeyPressEvent(sk::KeyPressEvent& e)
{
	std::cout << "Key Code: " << static_cast<int>(e.GetKeyCode()) << std::endl;

	return true;
}

int main()
{
	sk::Window* window = sk::Window::Create();
	window->SetVerticalSync(true);

	sk::Input::AttachWindow(window);

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

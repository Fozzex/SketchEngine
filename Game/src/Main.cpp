#include <iostream>
#include <Sketch/Sketch.h>

int main()
{
	sk::Window* window = sk::Window::Create();
	window->SetVerticalSync(true);

	while (!window->Closed())
	{
		window->SwapBuffers();
	}

	delete window;
}

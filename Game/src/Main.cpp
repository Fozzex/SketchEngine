#include <iostream>
#include <Sketch/Sketch.h>

int main()
{
	sk::Window window(1280, 720, "Sketch");
	window.SetVerticalSync(true);

	while (!window.Closed())
	{
		window.SwapBuffers();
	}
}

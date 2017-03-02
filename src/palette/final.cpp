#include "final.hpp"

Final::Final(shared_ptr<int> width, int height, shared_ptr<Color> c)
		: Scale (width, height)
{
	// assign pointer
	color = c;
	// and set value to black
	*color = Color (0, 0, 0);
}

Final::~Final()
{}

bool Final::click (Vertex mouse)
{
	// do nothing
	return false;
}

void Final::render()
{
	// set color
	color->bind();
	// start drawind rectangle
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(0, height);
	glVertex2i(*width, height);
	glVertex2i(*width, 0);
	// findsh
	glEnd();
	// draw white frame
	renderFrame();
}

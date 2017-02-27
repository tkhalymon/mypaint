#include "final.hpp"

Final::Final(shared_ptr<int> width, int height, int offset, shared_ptr<Color> c)
		: Scale (width, height, offset)
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
	glVertex2i(padding, offset + padding);
	glVertex2i(padding, offset + padding + height - 1);
	glVertex2i(*width - padding, offset + padding + height - 1);
	glVertex2i(*width - padding, offset + padding);
	// findsh
	glEnd();
	// draw white frame
	renderFrame();
}

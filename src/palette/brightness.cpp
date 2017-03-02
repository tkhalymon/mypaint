#include "brightness.hpp"

// pointer to window width, scale height, distance from top (offset), pointer to color shade
Brightness::Brightness(shared_ptr<int> width, int height, shared_ptr<Color> shade)
		: Scale (width, height)
{
	// scale beginning color
	lightColor = shade;
	// create a resulting color
	color = make_shared<Color>(0, 0, 0);
	// set current color to black
	// *color = Color(0, 0, 0);
	// set default value to left side of a scale
	// value = 1;
}

Brightness::~Brightness()
{

}

bool Brightness::click (Vertex mouse)
{
	// if mouse position is inside of a scale
	if (mouse.x() > 0 && mouse.x() < *width
	    && mouse.y() > 0 && mouse.y() < height)
	{
		// set scale current value
		value = mouse.x() / *width;
		update();
		return true;
	}
	else
	{
		return false;
	}
}

void Brightness::render()
{
	// draw a filled square
	glBegin(GL_QUADS);
	// start from black
	glColor3d(0, 0, 0);
	glVertex2i(0, 0);
	glVertex2i(0, height);
	// and to clean shade
	lightColor->bind();
	glVertex2i(*width, height);
	glVertex2i(*width, 0);
	// finish drawing
	glEnd();
	// draw frame
	renderFrame();
	// and current value pointer as arrow
	renderArrow();
}

void Brightness::update()
{
	for (int i = 0; i < 3; ++i)
		(*color)[i] = (*lightColor)[i] * value;
}
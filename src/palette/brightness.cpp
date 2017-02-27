#include "brightness.hpp"

// pointer to window width, scale height, distance from top (offset), pointer to color shade
Brightness::Brightness(shared_ptr<int> width, int height, int offset, shared_ptr<Color> shade)
		: Scale (width, height, offset)
{
	// scale beginning color
	lightColor = shade;
	// create a resulting color
	color = make_shared<Color>(*shade);
	// set current color to black
	*color = Color(0, 0, 0);
	// set default value to left side of a scale
	value = 1;
}

Brightness::~Brightness()
{

}

bool Brightness::click (Vertex mouse)
{
	// if mouse position is inside of a scale
	if (mouse.x() >= padding && mouse.x() < *width - padding
	    && mouse.y() >= offset + padding && mouse.y() < offset + padding + height)
	{
		// set scale current value
		value = mouse.x() - padding;
		// array to store color (RGB)
		unsigned char pixel[3];
		// get color from screen mouse.x() - x to start from glutGet(GLUT_WINDOW_WIDTH) - mouse.y() - y to start
		// from (width - y, because OpenGL counts from bottom of the window). 1, 1 - area size, GL_RB - color
		// scheme, GL_UNSIGNED_BYTE - return type, pixel - array to write to
		glReadPixels(mouse.x(), glutGet(GLUT_WINDOW_WIDTH) - mouse.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
		// set color form pixel data array
		*color = Color(pixel[0] / 255., pixel[1] / 255., pixel[2] / 255.);
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
	glVertex2i(padding, offset + padding);
	glVertex2i(padding, offset + padding + height);
	// and to clean shade
	lightColor->bind();
	glVertex2i(*width - padding, offset + padding + height);
	glVertex2i(*width - padding, offset + padding);
	// finish drawing
	glEnd();
	// draw frame
	renderFrame();
	// and current value pointer as arrow
	renderArrow();
}

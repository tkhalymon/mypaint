#include "lightness.hpp"

Lightness::Lightness(shared_ptr<int> width, int height, shared_ptr<Color> start)
		: Scale (width, height), startColor(start)
{
	// startColor = start;
	color = make_shared<Color>(0, 0, 0);
}

Lightness::~Lightness()
{

}

bool Lightness::click (Vertex mouse)
{
	if (mouse.x() > 0 && mouse.x() < *width
	    && mouse.y() > 0 && mouse.y() < height)
	{
		value = mouse.x() / *width;
		// unsigned char pixels[3];
		// glReadPixels(mouse.x(), glutGet(GLUT_WINDOW_WIDTH) - mouse.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
		// *color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
		double percent = value / (*width);
		*color = Color(startColor->red() * percent, startColor->green() * percent, startColor->blue() * percent);
		return true;
	}
	else
	{
		return false;
	}
}

void Lightness::render()
{
	glBegin(GL_QUADS);
	startColor->bind();
	// left edge
	glVertex2i(0, 0);
	glVertex2i(0, height);
	// white
	glColor3d(1, 1, 1);
	// rigth edge
	glVertex2i(*width, height);
	glVertex2i(*width, 0);
	glEnd();
	renderFrame();
	renderArrow();
}

void Lightness::update()
{
	for (int i = 0; i < 3; ++i)
		(*color)[i] = (*startColor)[i] + (1 - (*startColor)[i]) * (value);
}
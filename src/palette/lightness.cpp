#include "lightness.hpp"

Lightness::Lightness(shared_ptr<int> width, int height, int offset, shared_ptr<Color> brightness, shared_ptr<Color> final)
		: Toolbox (width, height, offset)
{
	darkColor = brightness;
	color = final;
}

Lightness::~Lightness()
{

}

bool Lightness::click (Vertex mouse)
{
	if (mouse.x() >= padding && mouse.x() < *width - padding
	    && mouse.y() >= offset + padding && mouse.y() < offset + padding + height)
	{
		value = mouse.x() - padding;
		unsigned char pixels[3];
		glReadPixels(mouse.x(), glutGet(GLUT_WINDOW_WIDTH) - mouse.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
		*color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
		return true;
	}
	else
	{
		return false;
	}
}

void Lightness::render()
{
	glBegin(GL_TRIANGLE_STRIP);
	darkColor->bind();
	glVertex2i(padding, offset + padding);
	glVertex2i(padding, offset + padding + height - 1);
	glColor3d(1, 1, 1);
	glVertex2i(*width - padding, offset + padding);
	glVertex2i(*width - padding, offset + padding + height - 1);
	glEnd();
	renderFrame();
	renderArrow();
}

void Lightness::update()
{
	unsigned char pixels[3];
	glReadPixels(padding + value, glutGet(GLUT_WINDOW_HEIGHT) - offset - padding - 1, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	*color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
	glutPostRedisplay();
}

shared_ptr<Color>& Lightness::colorPtr()
{
	return color;
}

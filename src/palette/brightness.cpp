#include "brightness.hpp"

Brightness::Brightness(shared_ptr<int> width, int height, int offset, shared_ptr<Color> shade)
		: Toolbox (width, height, offset)
{
	lightColor = shade;
	color = make_shared<Color>(*shade);
	value = *width - 2 * padding - 2;
}

Brightness::~Brightness()
{

}

bool Brightness::click (Vertex mouse)
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

void Brightness::render()
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor3d(0, 0, 0);
	glVertex2i(padding, offset + padding);
	glVertex2i(padding, offset + padding + height);
	lightColor->bind();
	glVertex2i(*width - padding, offset + padding);
	glVertex2i(*width - padding, offset + padding + height);
	glEnd();
	renderFrame();
	renderArrow();
}

void Brightness::update()
{
	unsigned char pixels[3];
	glReadPixels(padding + value, glutGet(GLUT_WINDOW_HEIGHT) - offset - padding - 2, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	*color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
	glutPostRedisplay();
}

shared_ptr<Color>& Brightness::colorPtr()
{
	return color;
}

#include "scale.hpp"

Scale::Scale(shared_ptr<int> width, int height)
		: width(width), height(height), value(0)
{

}

Scale::~Scale()
{

}

int Scale::getHeight() const
{
	// full height
	return height;
}

bool Scale::click(Vertex mouse)
{
	// if mouse actions aren't used
	return false;
}

void Scale::renderFrame()
{
	// line width = 1
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	// white
	glColor3d(1, 1, 1);
	glVertex2i(0, 0);
	glVertex2i(0, height + 1);
	glVertex2i(*width + 1, height + 1);
	glVertex2i(*width + 1, 0);
	glEnd();
}

void Scale::renderArrow()
{
	// line width = 1
	glLineWidth(1);
	// white color
	glColor3d(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex2i(value * *width - 3, height + 4);
	glVertex2i(value * *width + 3, height + 4);
	glVertex2i(value * *width, height - 4);
	glEnd();
}

shared_ptr<Color>& Scale::colorPtr()
{
	// shared pointer to color, currently selected on scale
	return color;
}

void Scale::update()
{
	// glutPostRedisplay();
	// unsigned char pixels[3];
	// glReadPixels(padding + value, glutGet(GLUT_WINDOW_HEIGHT) - offset - padding - 1, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	// *color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
	// glutPostRedisplay();
}

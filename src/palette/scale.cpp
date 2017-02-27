#include "scale.hpp"

const int Scale::padding = 15;

Scale::Scale(shared_ptr<int> width, int height, int offset)
		: width(width), height(height), offset(offset), value(1)
{

}

Scale::~Scale()
{

}

int Scale::getHeight() const
{
	// full height
	return height + padding;
}

int Scale::getOffset() const
{
	// distance from top of the screen
	return offset;
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
	glVertex2i(padding - 1, offset + padding);
	glVertex2i(padding - 1, offset + padding + height);
	glVertex2i(*width - padding + 1, offset + padding + height);
	glVertex2i(*width - padding + 1, offset + padding);
	glEnd();
}

void Scale::renderArrow()
{
	// line width = 1
	glLineWidth(1);
	// white color
	glColor3d(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex2i(padding + value - 3, offset + padding + height + 4);
	glVertex2i(padding + value + 3, offset + padding + height + 4);
	glVertex2i(padding + value, offset + padding + height - 4);
	glEnd();
}

shared_ptr<Color>& Scale::colorPtr()
{
	// shared pointer to color, currently selected on scale
	return color;
}

void Scale::update()
{
	unsigned char pixels[3];
	glReadPixels(padding + value, glutGet(GLUT_WINDOW_HEIGHT) - offset - padding - 1, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	*color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
	glutPostRedisplay();
}

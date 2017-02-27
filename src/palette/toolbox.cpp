#include "toolbox.hpp"

const int Toolbox::padding = 15;

Toolbox::Toolbox(shared_ptr<int> width, int height, int offset)
		: width(width), height(height), offset(offset), value(1)
{

}

Toolbox::~Toolbox()
{

}

int Toolbox::getHeight() const
{
	// full height
	return height + padding;
}

int Toolbox::getOffset() const
{
	return offset;
}

void Toolbox::renderFrame()
{
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glColor3d(1, 1, 1);
	glVertex2i(padding - 1, offset + padding);
	glVertex2i(padding - 1, offset + padding + height);
	glVertex2i(*width - padding + 1, offset + padding + height);
	glVertex2i(*width - padding + 1, offset + padding);
	glEnd();
}

void Toolbox::renderArrow()
{
	glLineWidth(1);
	glBegin(GL_TRIANGLES);
	glVertex2i(padding + value - 3, offset + padding + height + 4);
	glVertex2i(padding + value + 3, offset + padding + height + 4);
	glVertex2i(padding + value, offset + padding + height - 4);
	glEnd();
}

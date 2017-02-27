#include "rectangle.hpp"

Rectangle::Rectangle(Vertex topLeft, Color c, int lineWidth)
		: Figure(c), topLeft(topLeft), botRight(0, 0), lineWidth(lineWidth)
{

}

Rectangle::~Rectangle()
{

}

void Rectangle::render()
{
	color.bind();
	glLineWidth(lineWidth);
	glBegin(GL_LINE_LOOP);
	topLeft.glVertex();
	glVertex2i(topLeft.x(), botRight.y());
	botRight.glVertex();
	glVertex2i(botRight.x(), topLeft.y());
	glEnd();
}

void Rectangle::mouseMoved(const Vertex& position)
{
	botRight = position;
}
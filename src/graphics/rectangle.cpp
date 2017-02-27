#include "rectangle.hpp"

// set top left corner of rectangle, color and line width
Rectangle::Rectangle(Vertex topLeft, Color c, int lineWidth)
		: Figure(c), topLeft(topLeft), botRight(0, 0), lineWidth(lineWidth), filled(false)
{

}

Rectangle::~Rectangle()
{}

void Rectangle::render() const
{
	// set color
	color.bind();
	// set line width
	glLineWidth(lineWidth);
	// draw, regardless of filling enabled / disabled
	if (filled)
	{
		// filled square
		glBegin(GL_QUADS);
	}
	else
	{
		// lines loop
		glBegin(GL_LINE_LOOP);
	}
	// top left
	topLeft.glVertex();
	// bottom left
	glVertex2i(topLeft.x(), botRight.y());
	// bottom right
	botRight.glVertex();
	// top right
	glVertex2i(botRight.x(), topLeft.y());
	// finish drawing
	glEnd();
}

void Rectangle::mouseMoved(const Vertex& position)
{
	// set bottom right to mouse position
	botRight = position;
}
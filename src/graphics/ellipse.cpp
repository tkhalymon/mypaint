#include "ellipse.hpp"

Ellipse::Ellipse(Vertex center, Color c, int lineWidth)
		: Figure(c), center(center), radius(0, 0), lineWidth(lineWidth)
{}

Ellipse::~Ellipse()
{}

void Ellipse::render() const
{
	// set color
	color.bind();
	// set line width
	glLineWidth(lineWidth);
	// cyclic line strip
	glBegin(GL_LINE_LOOP);
	// angle from 0 to 2 * PI, step depends on radius
	for (double angle = 0; angle < 2 * M_PI; angle += 2. * M_PI / (double)(10 + (abs(radius.x()) + abs(radius.y())) / 10))
	{
		glVertex2d(center.x() + cos(angle) * radius.x(), center.y() + sin(angle) * radius.y());
	}
	glEnd();
}

void Ellipse::mouseMoved(const Vertex& position)
{
	// calculate top left corner
	Vertex topLeft = Vertex(center.x() - radius.x(), center.y() - radius.y());
	// new radius
	radius = Vertex((position.x() - topLeft.x()) / 2, (position.y() - topLeft.y()) / 2);
	// new center
	center = Vertex(topLeft.x() + radius.x(), topLeft.y() + radius.y());
}
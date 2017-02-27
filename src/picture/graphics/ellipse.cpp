#include "ellipse.hpp"

Ellipse::Ellipse(Vertex center, Color c, int lineWidth) : Figure(c), center(center), radius(0, 0), lineWidth(lineWidth)
{

}

Ellipse::~Ellipse()
{

}

void Ellipse::render()
{
	color.bind();
	glLineWidth(lineWidth);
	glBegin(GL_LINE_LOOP);
	for (double angle = 0; angle < 2 * M_PI; angle += 2. * M_PI / (double)(10 + (abs(radius.x()) + abs(radius.y())) / 10))
	{
		glVertex2d(center.x() + cos(angle) * radius.x(), center.y() + sin(angle) * radius.y());
	}
	glEnd();
}

void Ellipse::mouseMoved(const Vertex& position)
{
	Vertex topLeft = Vertex(center.x() - radius.x(), center.y() - radius.y());
	radius.x((position.x() - topLeft.x()) / 2);
	radius.y((position.y() - topLeft.y()) / 2);
	center = Vertex(topLeft.x() + radius.x(), topLeft.y() + radius.y());
}
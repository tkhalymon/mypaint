#include "ellipse.hpp"

Ellipse::Ellipse(Vertex center, Color c, int lineWidth) : Figure(c, lineWidth), center(center)
{

}

Ellipse::~Ellipse()
{

}

void Ellipse::render()
{
	bindColor();
	glBegin(GL_LINE_LOOP);
	for (double angle = 0; angle < 2 * M_PI; angle += 10 / (abs(radiusX) + abs(radiusY) + 5.))
	{
		glVertex2d(center.x() + radiusX / 2 + cos(angle) * radiusX / 2, center.y() + radiusY / 2 + sin(angle) * radiusY / 2);
	}
	glEnd();
}

void Ellipse::mouseVertex(const Vertex& v)
{
	radiusX = v.x() - center.x();
	radiusY = v.y() - center.y();
}
#include "point.hpp"

Point::Point(int x, int y) : position(x, y)
{

}

Point::~Point()
{

}

void Point::render()
{
	glBegin(GL_POINTS);
	position.glVertex();
	glEnd();
}

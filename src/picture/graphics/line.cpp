#include "line.hpp"

Line::Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2)
{

}

Line::~Line()
{

}

void Line::render()
{
	glBegin(GL_LINES);
	glVertex2iv(start);
	glVertex2iv(end);
	glEnd();
}

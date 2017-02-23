#include "line.hpp"

Line::Line(Vertex start, Color c, int lineWidth) : Figure(c, lineWidth), start(start), end(start)
{}

Line::~Line()
{

}

void Line::render()
{
	bindColor();
	glBegin(GL_LINES);
	start.glVertex();
	end.glVertex();
	glEnd();
}

void Line::mouseVertex(const Vertex& v)
{
	end = v;
}

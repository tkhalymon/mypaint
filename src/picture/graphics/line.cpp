#include "line.hpp"

Line::Line(Vertex start, Color c, int width) : Figure(c), start(start), end(start), width(width)
{}

Line::~Line()
{

}

void Line::render()
{
	color.bind();
	glLineWidth(width);
	glBegin(GL_LINES);
	start.glVertex();
	end.glVertex();
	glEnd();
}

void Line::mouseMoved(const Vertex& position)
{
	end = position;
	glutPostRedisplay();
}

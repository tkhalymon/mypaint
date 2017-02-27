#include "line.hpp"

// Line start, color and width
Line::Line(Vertex start, Color c, int width) : Figure(c), start(start), end(start), width(width)
{}

Line::~Line()
{}

void Line::render() const
{
	// set color
	color.bind();
	// set line width
	glLineWidth(width);
	// start drawing
	glBegin(GL_LINES);
	// set 2 vertexes
	start.glVertex();
	end.glVertex();
	// finish drawing
	glEnd();
}

void Line::mouseMoved(const Vertex& position)
{
	// replace line end to current mouse position
	end = position;
	glutPostRedisplay();
}

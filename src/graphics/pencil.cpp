#include "pencil.hpp"

Pencil::Pencil(Vertex start, Color c) : Figure(c)
{
	// set starting point
	points.push_back(start);
}

Pencil::~Pencil()
{
	// remove all vertexes
	points.clear();
}

void Pencil::render() const
{
	// set color
	color.bind();
	// set line width to 1
	glLineWidth(1);
	// start drawing set of connected lines
	glBegin(GL_LINE_STRIP);
	// draw all lines
	for (list<Vertex>::const_iterator i = points.begin(); i != points.end(); ++i)
	{
		i->glVertex();
	}
	// finish drawing
	glEnd();
}

void Pencil::mouseMoved(const Vertex& v)
{
	// if we already have a line
	if (points.size() > 1)
	{	
		// get penultimate and last points
		Vertex prelast = *(-- --points.end());
		// last vertex
		Vertex last = points.back();
		// if new point is a prolongation of last line
		if ((prelast - last).proportional(v - last))
		{
			// just replace a previous point with a current mouse position
			points.back() = v;
		}
		else
		{
			// add a new point
			points.push_back(v);
		}
	}
	else
	{
		// add new point
		points.push_back(v);
	}
	// redraw screen
	glutPostRedisplay();
}

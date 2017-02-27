#include "pencil.hpp"

Pencil::Pencil(Vertex start, Color c, int lineWidth) : Figure(c)
{
	points.push_back(start);

}

Pencil::~Pencil()
{
	points.clear();
}

void Pencil::render()
{
	color.bind();
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	for (list<Vertex>::iterator i = points.begin(); i != points.end(); ++i)
	{
		i->glVertex();
	}
	glEnd();
}

void Pencil::mouseMoved(const Vertex& v)
{
	// if we already have a line
	if (points.size() > 1)
	{	
		// get prelast and last points
		Vertex prelast = *(-- --points.end());
		Vertex last = points.back();
		// if new point is a prolongation of last line
		if ((prelast - last).proportional(v - last))
		{
			// just replace a prevous point with a current mouse position
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
		points.push_back(v);
		// glFlush();
	}
	glutPostRedisplay();
}

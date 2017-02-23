#include "pencil.hpp"

Pencil::Pencil(Vertex start, Color c, int lineWidth) : Figure(c, lineWidth)
{
	points.push_back(start);

}

Pencil::~Pencil()
{

}

void Pencil::render()
{
	bindColor();
	glBegin(GL_LINE_STRIP);
	for (list<Vertex>::iterator i = points.begin(); i != points.end(); ++i)
	{
		i->glVertex();
	}
	glEnd();
}

void Pencil::mouseVertex(const Vertex& v)
{
	if (points.size() > 2)
	{	
		Vertex prelast = *(-- --points.end());
		Vertex last = points.back();
		if (!(prelast - last).proportional(v - last))
		{
			points.push_back(v);
		}
		else
		{
			points.back() = v;
		}
	}
	else
	{
		points.push_back(v);
	}
}

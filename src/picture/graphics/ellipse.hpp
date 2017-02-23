#ifndef __ELLIPSE_HPP__
#define __ELLIPSE_HPP__

class Ellipse;

#include <math.h>

#define _USE_MATH_DEFINES

#include "figure.hpp"

class Ellipse : public Figure
{
public:
	Ellipse(Vertex center, Color c, int lineWidth);
	~Ellipse();

	void render();

	void mouseVertex(const Vertex& v);

private:

	Vertex center;
	int radiusX;
	int radiusY;
	int lineWidth;

};

#endif
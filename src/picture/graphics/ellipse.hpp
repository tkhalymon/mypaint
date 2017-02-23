#ifndef __ELLIPSE_HPP__
#define __ELLIPSE_HPP__

class Ellipse;

#include "figure.hpp"

class Ellipse
{
public:
	Ellipse(Vertex center, int radX, int radY);
	~Ellipse();

	void render();

private:

	Vertex center;
	int radiusX;
	int radiusY;
};

#endif
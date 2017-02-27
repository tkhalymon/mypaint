#ifndef __ELLIPSE_HPP__
#define __ELLIPSE_HPP__

class Ellipse;

#include <math.h>

// to use math PI constant
#define _USE_MATH_DEFINES

/*
	class Ellipse

	Round geometric figure with two radiuses
*/

class Ellipse;

#include "figure.hpp"

class Ellipse : public Figure
{
public:
	Ellipse(Vertex center, Color c, int lineWidth);
	~Ellipse();

	void render();

	void mouseMoved(const Vertex& v);

private:

	Vertex center;
	Vertex radius;
	int lineWidth;
};

#endif
#ifndef __GRAPHICS_ELLIPSE_HPP__
#define __GRAPHICS_ELLIPSE_HPP__

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
	// draw
	void render() const;
	// handle new mouse vertex
	void mouseMoved(const Vertex& v);

private:

	// coordinates of center
	Vertex center;
	// x and y radiuses
	Vertex radius;
	// line width
	int lineWidth;
};

#endif // __GRAPHICS_ELLIPSE_HPP__
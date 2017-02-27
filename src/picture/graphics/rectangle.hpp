#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

class Rectangle;

/*
	class Rectangle
*/

class Rectangle;

#include "figure.hpp"

class Rectangle : public Figure
{
public:
	Rectangle(Vertex center, Color c, int lineWidth);
	~Rectangle();

	void render();

	void mouseMoved(const Vertex& v);

private:

	Vertex topLeft;
	Vertex botRight;
	int lineWidth;
};

#endif
#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

class Rectangle;

/*
	class Rectangle

	supports line width
	can be filled, or empty
*/

class Rectangle;

#include "figure.hpp"

class Rectangle : public Figure
{
public:
	Rectangle(Vertex center, Color c, int lineWidth);
	~Rectangle();
	// draw
	void render();
	// submit new mouse vertex
	void mouseMoved(const Vertex& v);

private:
	// corner vertexes
	Vertex topLeft;
	Vertex botRight;
	int lineWidth;
	bool filled;
};

#endif
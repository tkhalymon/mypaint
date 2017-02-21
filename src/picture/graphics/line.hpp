#ifndef __LINE_HPP__
#define __LINE_HPP__

#include <GL/glut.h>
#include <iostream>

#include "figure.hpp"

class Line : public Figure
{
public:
	Line(int x1, int y1, int x2, int y2);
	~Line();

	void render();

private:

	Vertex start;
	Vertex end;
};

#endif
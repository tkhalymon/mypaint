#ifndef __LINE_HPP__
#define __LINE_HPP__

#include <GL/glut.h>
#include <iostream>

class Point;

#include "figure.hpp"

class Point : public Figure
{
public:
	Point(int x, int y);
	~Point();

	void render();

private:

	Vertex position;
};

#endif
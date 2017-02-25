#ifndef __FIGURE_HPP__
#define __FIGURE_HPP__

#include <GL/glut.h>

class Figure;

#include "vertex.hpp"
#include "color.hpp"

class Figure
{
public:
	Figure(Color c, int lineWidth);
	virtual ~Figure();

	virtual void render() = 0;

	void bindColor();

	virtual void mouseVertex(const Vertex& v) = 0;

private:

	Color color;
	int lineWidth;
};

#endif // __FIGURE_HPP__
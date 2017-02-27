#ifndef __FIGURE_HPP__
#define __FIGURE_HPP__

#include <GL/glut.h>

/*
	class Figure

	Abstract Base for geometric figure
	by default it has only color.
*/

class Figure;

#include "vertex.hpp"
#include "color.hpp"

class Figure
{
public:
	// each figure has color
	Figure(Color c);

	virtual ~Figure();

	// renders a complete figure
	virtual void render() = 0;

	// called when this object is in creation progress
	virtual void mouseMoved(const Vertex& v) = 0;

protected:

	// figure color
	Color color;
	// is figure selected
	bool isSelected;
};

#endif // __FIGURE_HPP__
#ifndef __GRAPHICS_FIGURE_HPP__
#define __GRAPHICS_FIGURE_HPP__

#include <GL/glut.h>
#include <memory>
#include <map>

using std::shared_ptr;
using std::make_shared;
using std::map;

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
	enum class Type { Pencil, Line, Ellipse, Rectangle };
	// figure color
	Figure(Color c);
	virtual ~Figure();
	// renders a complete figure
	virtual void render() const = 0;
	// called when this object is in creation progress
	virtual void mouseMoved(const Vertex& v) = 0;
	// finish figure creation
	void finish();
	// is completely created
	bool finished();

	static int getTypeId(Figure::Type t);
	
	static Figure::Type getTypeById(int);
	
protected:

	// figure color
	Color color;
	// is figure selected
	bool isSelected;
	// is creation finished
	bool isFinished;
};

#endif // __GRAPHICS_FIGURE_HPP__
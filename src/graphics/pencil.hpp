#ifndef __PENCIL_HPP__
#define __PENCIL_HPP__

#include <GL/glut.h>
#include <list>

using std::list;

class Pencil;

/*
	class Pencil

	Incstrument that draws a curve, folowing mouse position
*/

#include "figure.hpp"

class Pencil : public Figure
{
public:
	// set first vertex and color
	Pencil(Vertex start, Color c);
	~Pencil();
	// draw
	void render() const;
	// handle mouse moving (in pressed state)
	void mouseMoved(const Vertex& v);

private:
	// all vertexes
	list<Vertex> points;
};

#endif // __PENCIL_HPP__
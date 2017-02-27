#ifndef __PENCIL_HPP__
#define __PENCIL_HPP__

#include <GL/glut.h>
#include <list>

using std::list;

class Pencil;

#include "figure.hpp"

class Pencil : public Figure
{
public:
	Pencil(Vertex start, Color c, int lineWidth);
	~Pencil();

	void render();

	void mouseMoved(const Vertex& v);

	int size (){return points.size();}

private:

	list<Vertex> points;
};

#endif // __PENCIL_HPP__
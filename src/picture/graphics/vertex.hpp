#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include <GL/glut.h>

class Vertex
{
public:
	Vertex(int x, int y);
	~Vertex();

	int& x();
	int& y();

	void glVertex();

private:

	int coordinate[2];
};

#endif
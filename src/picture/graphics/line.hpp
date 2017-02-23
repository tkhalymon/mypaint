#ifndef __LINE_HPP__
#define __LINE_HPP__

#include <GL/glut.h>

class Line;

#include "figure.hpp"
#include "../../tools/position.hpp"

class Line : public Figure
{
public:
	Line(Vertex start, Color c, int lineWidth);
	~Line();

	void render();

	void mouseVertex(const Vertex& v);

private:

	Vertex start;
	Vertex end;
};

#endif // __LINE_HPP__
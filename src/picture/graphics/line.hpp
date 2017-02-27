#ifndef __LINE_HPP__
#define __LINE_HPP__

#include <GL/glut.h>

class Line;

#include "figure.hpp"

class Line : public Figure
{
public:
	Line(Vertex start, Color c, int lineWidth);
	~Line();

	void render();

	void mouseMoved(const Vertex& v);

private:

	// coordinates of line ends
	Vertex start;
	Vertex end;

	int width;
};

#endif // __LINE_HPP__
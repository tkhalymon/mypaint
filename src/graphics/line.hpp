#ifndef __LINE_HPP__
#define __LINE_HPP__

#include <GL/glut.h>

class Line;

#include "figure.hpp"

/*
	class Line

	A straight line.
*/

class Line : public Figure
{
public:
	Line(Vertex start, Color c, int lineWidth);
	~Line();
	// draw the line
	void render() const;
	// handle mouse moving (int pressed state)
	void mouseMoved(const Vertex& v);

private:

	// coordinates of line ends
	Vertex start;
	Vertex end;
	// line width
	int width;
};

#endif // __LINE_HPP__
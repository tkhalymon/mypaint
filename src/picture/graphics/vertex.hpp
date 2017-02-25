#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include <GL/glut.h>

class Vertex
{
public:
	Vertex(int x, int y);
	~Vertex();

	// setters
	void x(double value);
	void y(double value);

	// set both values
	void set (double x, double y);

	// getters
	const double& x() const;
	const double& y() const;

	// are coordinates proportional
	bool proportional(Vertex);

	// convert to array operator
	operator double const* () const;

	Vertex operator - (Vertex) const;

	// render as OpenGL vertex
	void glVertex();

private:

	// coordinates
	double data[2];

	// indexes of coordinates in array
	static const int x_index;
	static const int y_index;
};

#endif // __VERTEX_HPP__
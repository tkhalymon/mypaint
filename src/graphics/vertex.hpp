#ifndef __GRAPHICS_VERTEX_HPP__
#define __GRAPHICS_VERTEX_HPP__

#include <GL/glut.h>

class Vertex
{
public:
	Vertex(const double& x, const double& y);
	~Vertex();
	// setters
	void x(const double& value);
	void y(const double& value);
	// set both values
	void set (const double& x, const double& y);
	// getters
	const double& x() const;
	const double& y() const;
	// are coordinates proportional
	bool proportional(Vertex) const;
	// + and - operators
	Vertex operator - (const Vertex&) const;
	Vertex operator + (const Vertex&) const;
	// render as OpenGL vertex
	void glVertex() const;

private:

	// coordinates
	double data[2];

	// indexes of coordinates in array
	static const int x_index;
	static const int y_index;
};

#endif // __GRAPHICS_VERTEX_HPP__
#include "vertex.hpp"

Vertex::Vertex(int x, int y)
{
	coordinate[0] = x;
	coordinate[1] = y;
}

Vertex::~Vertex()
{}

// Vertex::operator const int*() const
// {
// 	return coordinate;
// }

void Vertex::glVertex()
{
	glVertex2iv(coordinate);
}

#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

class Vertex
{
public:
	Vertex(int x, int y);
	~Vertex();

	operator const int*() const;

private:

	int coordinate[2];
};

#endif
#include "vertex.hpp"

// array indexes
const int Vertex::x_index = 0;
const int Vertex::y_index = 1;

Vertex::Vertex(const double& x, const double& y) : data {x, y}
{}

Vertex::~Vertex()
{}

void Vertex::x(const double& value)
{
	data[x_index] = value;
}

void Vertex::y(const double& value)
{
	data[y_index] = value;
}

void Vertex::set (const double& x, const double& y)
{
	data[x_index] = x;
	data[y_index] = y;
}

const double& Vertex::x() const
{
	return data[x_index];
}

const double& Vertex::y() const
{
	return data[y_index];
}

bool Vertex::proportional(Vertex v) const
{
	// if x coordinate of this == 0
	if (data[x_index] == 0)
	{
		// and x coordinate of v == 0
		if (v.data[x_index] == 0)
		{
			// vertex coordinates are proportional
			return true;
		}
		else
		{
			// vertex coordinates are not proportional
			return false;
		}
	}
	else
	{
		// if v.y / v.x * this->x == this->x
		if (data[y_index] == v.data[y_index] * data[x_index] / v.data[x_index])
		{
			// vertex coordinates are proportional
			return true;
		}
		else
		{
			// vertex coordinates are not proportional
			return false;
		}
	}
}

Vertex Vertex::operator - (const Vertex& v) const
{
	return Vertex(v.data[x_index] - data[x_index], v.data[y_index] - data[y_index]);
}

Vertex Vertex::operator + (const Vertex& v) const
{
	return Vertex(v.data[x_index] + data[x_index], v.data[y_index] + data[y_index]);
}

void Vertex::glVertex() const
{
	glVertex2dv(data);
}

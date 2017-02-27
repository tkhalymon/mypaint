#include "vertex.hpp"

const int Vertex::x_index = 0;
const int Vertex::y_index = 1;

Vertex::Vertex(const double& x, const double& y)
{
	data[x_index] = x;
	data[y_index] = y;
}

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

bool Vertex::proportional(Vertex v)
{
	if (data[x_index] == 0)
	{
		if (v.data[x_index] == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (data[y_index] == v.data[y_index] * data[x_index] / v.data[x_index])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

Vertex::operator double const* () const
{
	return data;
}

Vertex Vertex::operator - (const Vertex& v) const
{
	return Vertex(v.data[x_index] - data[x_index], v.data[y_index] - data[y_index]);
}

Vertex Vertex::operator + (const Vertex& v) const
{
	return Vertex(v.data[x_index] + data[x_index], v.data[y_index] + data[y_index]);
}

void Vertex::glVertex()
{
	glVertex2dv(data);
}

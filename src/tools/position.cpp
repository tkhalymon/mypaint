#include "position.hpp"

const int Position::x_index = 0;
const int Position::y_index = 1;

Position::Position (int x, int y) : data{x, y}
{}

void Position::x(int value)
{
	data[x_index] = value;
}

void Position::y(int value)
{
	data[y_index] = value;
}

void Position::set (int x, int y)
{
	data[x_index] = x;
	data[y_index] = y;
}

const int& Position::x() const
{
	return data[x_index];
}

const int& Position::y() const
{
	return data[y_index];
}

Position::operator int const* () const
{
	return data;
}

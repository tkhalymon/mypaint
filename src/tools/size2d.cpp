#include "size2d.hpp"

const int Size2d::width_index = 0;
const int Size2d::height_index = 1;

Size2d::Size2d (int width, int height) : data{width, height}
{}

void Size2d::width(int value)
{
	data[width_index] = value;
}

void Size2d::height(int value)
{
	data[height_index] = value;
}

void Size2d::set (int width, int height)
{
	data[width_index] = width;
	data[height_index] = height;
}

const int& Size2d::width() const
{
	return data[width_index];
}

const int& Size2d::height() const
{
	return data[height_index];
}

Size2d::operator int const* () const
{
	return data;
}

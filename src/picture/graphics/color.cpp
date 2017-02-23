#include "color.hpp"

const int Color::red_index = 0;
const int Color::green_index = 1;
const int Color::blue_index = 2;

Color::Color(double red, double green, double blue) : data{red, green, blue}
{}

Color::Color(const Color& c)
{
	for (int i = 0; i < 3; ++i)
	{
		data[i] = c.data[i];
	}
}

Color::~Color()
{}

void Color::set(double red, double green, double blue)
{
	data[red_index] = red;
	data[green_index] = green;
	data[blue_index] = blue;
}

void Color::bind() const
{
	glColor3dv(data);
}
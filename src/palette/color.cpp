#include "color.hpp"

const int Color::red_index = 0;
const int Color::green_index = 1;
const int Color::blue_index = 2;

Color::Color(int red, int green, int blue) : data{red, green, blue}
{}

Color::~Color()
{}

void Color::set(int red, int green, int blue)
{
	data[red_index] = red;
	data[green_index] = green;
	data[blue_index] = blue;
}

void Color::bind() const
{
	glColor3iv(data);
}

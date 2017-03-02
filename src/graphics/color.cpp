#include "color.hpp"

const int Color::red_index = 0;
const int Color::green_index = 1;
const int Color::blue_index = 2;
const int Color::alpha_index = 3;

Color::Color(const float& red, const float& green, const float& blue, const float& alpha) : data{red, green, blue, alpha}
{}

Color::Color(const Color& c)
{
	for (int i = 0; i < 4; ++i)
	{
		data[i] = c.data[i];
	}
}

Color::~Color()
{}

void Color::setRed(const float& r)
{
	data[red_index] = r;
}

void Color::setGreen(const float& g)
{
	data[green_index] = g;
}

void Color::setBlue(const float& b)
{
	data[blue_index] = b;
}

void Color::setAlpha(const float& a)
{
	data[alpha_index] = a;
}

void Color::set(const float& red, const float& green, const float& blue, const float& alpha)
{
	data[red_index] = red;
	data[green_index] = green;
	data[blue_index] = blue;
	if (alpha >= 0) data[alpha_index] = alpha;
}

const float& Color::red() const
{
	return data[red_index];
}

const float& Color::green() const
{
	return data[green_index];
}

const float& Color::blue() const
{
	return data[blue_index];
}

const float& Color::alpha() const
{
	return data[alpha_index];
}

void Color::bind() const
{
	// set OpenGL color in RGBA format
	glColor4fv(data);
}

float& Color::operator[] (int index)
{
	if (index >= 0 && index < 4)
	{
		return data[index];
	}
	else
	{
		throw "Invalid index in color";
	}
}
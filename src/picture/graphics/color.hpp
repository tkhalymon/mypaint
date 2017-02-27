#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <GL/glut.h>

class Color
{
public:
	Color(const float& red, const float& green, const float& blue);
	// copy constructor
	Color(const Color&);
	~Color();
	// set new color
	void set(const float& red, const float& green, const float& blue);
	// set as current
	void bind() const;
private:

	// color data
	float data[3];
	// components indexes in array
	static const int red_index;
	static const int green_index;
	static const int blue_index;
};

#endif
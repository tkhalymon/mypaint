#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <GL/glut.h>

class Color
{
public:
	Color(double red, double green, double blue);
	Color(const Color&);
	~Color();

	// set new color
	void set(double red, double green, double blue);

	// set as current
	void bind() const;

private:

	double data[3];
	static const int red_index;
	static const int green_index;
	static const int blue_index;
};

#endif
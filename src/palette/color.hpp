#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <GL/glut.h>

class Color
{
public:
	Color(int red, int green, int blue);
	~Color();

	// set new color
	void set(int red, int green, int blue);

	// set as current
	void bind() const;

private:

	int data[3];
	static const int red_index;
	static const int green_index;
	static const int blue_index;
};

#endif
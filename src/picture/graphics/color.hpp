#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <GL/glut.h>

class Color
{
public:
	Color(float red, float green, float blue);
	Color(const Color&);
	~Color();

	// set new color
	void set(float red, float green, float blue);

	// set as current
	void bind() const;

private:

	float data[3];
	static const int red_index;
	static const int green_index;
	static const int blue_index;
};

#endif
#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <GL/glut.h>

class Color;

/*
	class Color

	stores drawind color
*/

class Color
{
public:
	Color(const float& red, const float& green, const float& blue, const float& alpha = 1);
	// copy constructor
	Color(const Color&);
	~Color();
	// setters
	void setRed(const float& r);
	void setGreen(const float& g);
	void setBlue(const float& b);
	void setAlpha(const float& a);
	void set(const float& red, const float& green, const float& blue, const float& alpha = -1);
	// getters
	const float& red() const;
	const float& green() const;
	const float& blue() const;
	const float& alpha() const;
	// set as current
	void bind() const;
private:

	// red, green, blue, alpha (transparency)
	float data[4];
	// components indexes in array
	static const int red_index;
	static const int green_index;
	static const int blue_index;
	static const int alpha_index;
};

#endif
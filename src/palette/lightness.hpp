#ifndef __LIGHTNESS_HPP__
#define __LIGHTNESS_HPP__

#include "scale.hpp"

class Lightness : public Scale
{
public:
	// startColor is a color wrom which the scale will start, and final is a resulting color
	Lightness(shared_ptr<int> width, int height, int offset, shared_ptr<Color> start, shared_ptr<Color> final);
	~Lightness();
	// mouse handler
	bool click(Vertex mouse);
	// drawing method
	void render();
	// refresh scale according to previous scales

private:
	shared_ptr<Color> startColor;
};

#endif // __LIGHTNESS_HPP__
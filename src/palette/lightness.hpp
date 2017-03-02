#ifndef __PALETTE_LIGHTNESS_HPP__
#define __PALETTE_LIGHTNESS_HPP__

#include "scale.hpp"

class Lightness : public Scale
{
public:
	// startColor is a color wrom which the scale will start, and final is a resulting color
	Lightness(shared_ptr<int> width, int height, shared_ptr<Color> start);
	~Lightness();
	// mouse handler
	bool click(Vertex mouse);
	// drawing method
	void render();
	// refresh scale according to previous scales
	void update();

private:
	shared_ptr<Color> startColor;
};

#endif // __PALETTE_LIGHTNESS_HPP__
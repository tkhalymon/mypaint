#ifndef __LIGHTNESS_HPP__
#define __LIGHTNESS_HPP__

#include "toolbox.hpp"

class Lightness : public Toolbox
{
public:
	// brightness is a color wrom which the scale will start, and final is a resulting color
	Lightness(shared_ptr<int> width, int height, int offset, shared_ptr<Color> brightness, shared_ptr<Color> final);
	~Lightness();

	bool click(Vertex mouse);
	
	void render();

	void update();

	shared_ptr<Color>& colorPtr();

private:

	shared_ptr<Color> darkColor;
};

#endif // __LIGHTNESS_HPP__
#ifndef __PALETTE_BRIGHTNESS_HPP__
#define __PALETTE_BRIGHTNESS_HPP__

#include "scale.hpp"

class Brightness;

/*
	class Brightness

	selects color brom black to selected shade
*/

class Brightness : public Scale
{
public:
	// pointer to window width, scale height, distance from top (offset), pointer to color shade
	Brightness(shared_ptr<int> width, int height, int offset, shared_ptr<Color> shade);
	~Brightness();
	// handles mouse click and drag (move pressed)
	bool click(Vertex mouse);
	// draw scale
	void render();
	
private:
	shared_ptr<Color> lightColor;
};

#endif // __PALETTE_BRIGHTNESS_HPP__
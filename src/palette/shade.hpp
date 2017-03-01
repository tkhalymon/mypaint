#ifndef __PALETTE_SHADE_HPP__
#define __PALETTE_SHADE_HPP__

#include <memory>

using std::shared_ptr;
using std::make_shared;

#include "scale.hpp"

// shade of color

class Shade : public Scale
{
public:
	// constructor, which takes parameters 
	Shade(shared_ptr<int> width, int height, int offset);
	~Shade();
	// mouse click event
	bool click(Vertex mouse);
	// draw
	void render();
	// update scale, when dependent scales changes
	void update();
	// shared pointer to color selected on scale
	shared_ptr<Color>& colorPtr();
private:

	// gradient colors
	static const double colors[4][3];
};

#endif // __PALETTE_SHADE_HPP__
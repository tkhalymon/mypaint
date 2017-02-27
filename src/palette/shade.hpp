#ifndef __SHADE_HPP__
#define __SHADE_HPP__

#include <memory>

using std::shared_ptr;
using std::make_shared;

#include "toolbox.hpp"

// shade of color

class Shade : public Toolbox
{
public:
	// constructor, which takes parameters 
	Shade(shared_ptr<int> width, int height, int offset);
	~Shade();
	bool click(Vertex mouse);
	void render();
	void update();
	shared_ptr<Color>& colorPtr();
private:

	// gradient colors
	static const double colors[4][3];
};

#endif // __SHADE_HPP__
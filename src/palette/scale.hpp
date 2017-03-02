#ifndef __PALETTE_TOOLBOX_HPP__
#define __PALETTE_TOOLBOX_HPP__

#include <memory>

using std::shared_ptr;
using std::make_shared;

#include "../graphics/vertex.hpp"
#include "../graphics/color.hpp"

class Scale
{
public:
	// shared pointer to width, because it's related to window size
	Scale(shared_ptr<int> width, int height);
	virtual ~Scale();
	// scale height with paddings
	int getHeight() const;
	// mouse click handler
	virtual bool click(Vertex mouse);
	// renders a scale in current window, returns true, if this scale has been clicked
	virtual void render() = 0;
	// just a white frame
	void renderFrame();
	// arrow, that points to current value
	void renderArrow();
	// update color when dependent color changed
	virtual void update();
	// get shared pointer to resulting color
	shared_ptr<Color>& colorPtr();

protected:
	// related to window width
	shared_ptr<int> width;
	// resulting color value
	shared_ptr<Color> color;
	// scale height
	int height;
	// last mouse position by x
	double value;
};

#endif /// __PALETTE_TOOLBOX_HPP__
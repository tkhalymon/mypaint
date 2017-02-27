#ifndef __TOOLBOX_HPP__
#define __TOOLBOX_HPP__

#include <memory>

using std::shared_ptr;
using std::make_shared;

#include "../graphics/vertex.hpp"
#include "../graphics/color.hpp"

class Scale
{
public:
	// shared pointer to width, because it's related to window size
	Scale(shared_ptr<int> width, int height, int offset);
	virtual ~Scale();
	// scale height with paddings
	int getHeight() const;
	// get vertical offset from top
	int getOffset() const;
	// mouse click handler
	virtual bool click(Vertex mouse);
	// renders a scale in current window, returns true, if this scale has been clicked
	virtual void render() = 0;
	// just a white frame
	void renderFrame();
	// arrow, that points to current value
	void renderArrow();
	// update color when dependent color changed
	void update();
	// get shared pointer to resulting color
	shared_ptr<Color>& colorPtr();

protected:
	// distance from window borders and other toolboxes
	static const int padding;
	// related to window width
	shared_ptr<int> width;
	// resulting color value
	shared_ptr<Color> color;
	// scale height
	int height;
	// distance from top of the window
	int offset;
	// last mouse position by x
	int value;
};

#endif /// __TOOLBOX_HPP__
#ifndef __TOOLBOX_HPP__
#define __TOOLBOX_HPP__

#include <memory>

using std::shared_ptr;
using std::make_shared;

#include "../picture/graphics/vertex.hpp"
#include "../picture/graphics/color.hpp"

class Toolbox
{
public:
	// shared pointer to width, because it's related to window size
	Toolbox(shared_ptr<int> width, int height, int offset);
	virtual ~Toolbox();
	// toolbox height with paddings
	int getHeight() const;
	// get vertical offset from top
	int getOffset() const;
	// mouse click handler
	virtual bool click(Vertex mouse) = 0;
	// renders a toolbox in current window, returns true, if this toolbox has been clicked
	virtual void render() = 0;
	// just a white frame
	void renderFrame();
	// arrow, that points to current value
	void renderArrow();
	// update color when dependent color changed
	virtual void update() = 0;
	// get shared pointer to resulting color
	virtual shared_ptr<Color>& colorPtr() = 0;

protected:
	// distance from window borders and other toolboxes
	static const int padding;
	// related to window width
	shared_ptr<int> width;
	// resulting color value
	shared_ptr<Color> color;
	// toolbox height
	int height;
	// distance from top of the window
	int offset;
	// last mouse position by x
	int value;
};

#endif /// __TOOLBOX_HPP__
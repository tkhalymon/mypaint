#ifndef __TOOLBOX_TOOLS_HPP__
#define __TOOLBOX_TOOLS_HPP__

#include <GL/glut.h>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;
using std::vector;

class Tools;

/*
	class Tools

	Contains toolboxes, to set up current drawing options.
*/

#include "../window/window.hpp"
#include "linewidth.hpp"
#include "instrument.hpp"

class Tools : public Window
{
public:
	// width, height, title - are for window constructor. lineWidth - for toolbox
	Tools(const int& width, const int& height, const char* title, shared_ptr<Picture> picture);
	~Tools();
	// rendering function
	void display();
	// mouse button pressing
	void mousePress(const int& button, const int& state, const Vertex& mousePos);
	// calls when user changes window size
	void reshape(const int& width, const int& height);

private:
	// vector of all toolboxes
	vector<shared_ptr<Toolbox>> toolboxes;
	// toolbox width (shared by all toolboxes) - window width - left and right paddings
	shared_ptr<int> toolBoxWidth;
	// distances from window edges
	shared_ptr<int> padding;
	// pointer to picture
	shared_ptr<Picture> picture;
};

#endif // __TOOLBOX_TOOLS_HPP__
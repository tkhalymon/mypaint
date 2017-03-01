#ifndef __TOOLBOX_TOOLS_HPP__
#define __TOOLBOX_TOOLS_HPP__

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;
using std::vector;

class Tools;

#include "../window/window.hpp"
#include "linewidth.hpp"

class Tools : public Window
{
public:
	Tools(const int& width, const int& height, const char* title, shared_ptr<int> lineWidth);
	~Tools();

	// rendering function
	void display();
	// mouse button pressing
	void mousePress(const int& button, const int& state, const Vertex& mousePos);
	// mouse moving with buttons pressed (drag)
	void mousePressMove(const Vertex& mousePos);
	// calls when user changes window size
	void reshape(const int& width, const int& height);

private:
	vector<shared_ptr<Toolbox>> toolboxes;
};

#endif // __TOOLBOX_TOOLS_HPP__
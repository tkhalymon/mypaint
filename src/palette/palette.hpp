#ifndef __PALETTE_HPP__
#define __PALETTE_HPP__

#include <GL/glut.h>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

#include "../window/window.hpp"
#include "../picture/graphics/color.hpp"
#include "shade.hpp"
#include "brightness.hpp"
#include "lightness.hpp"
#include "final.hpp"

class Palette : public Window
{
public:
	Palette(int width, int height, const char* title, shared_ptr<Color>);
	~Palette();
	
	// rendering function
	virtual void display();
	// mouse button pressing
	virtual void mousePress(const int& button, const int& state, const Vertex& mousePos);
	// mouse moving
	virtual void mouseMove(const Vertex& mousePos);
	// mouse moving with buttons pressed (drag)
	virtual void mousePressMove(const Vertex& mousePos);
	// keyboard key press
	virtual void keyPress(unsigned char key, const Vertex& mousePos);
	// keyboard special key press (F1-F12, Arrows, etc.)
	virtual void keyPressSpecial(const int& key, const Vertex& mousePos);
	// calls when user changes window size
	void reshape(const int& width, const int& height);

private:

	vector<shared_ptr<Toolbox>> toolboxes;

	static Vertex shadePanel[4];
	
	std::vector<Color> colors;

	shared_ptr<Color> color;
};

#endif // __PALETTE_HPP__
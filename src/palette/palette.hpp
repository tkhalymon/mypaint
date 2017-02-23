#ifndef __PALETTE_HPP__
#define __PALETTE_HPP__

#include <GL/glut.h>

#include "../window.hpp"

class Palette : public Window
{
public:
	Palette(int width, int height, const char* title);
	~Palette();
	
	// rendering function
	virtual void display();
	// mouse button pressing
	virtual void mousePress(int button, int state, Position mousePos);
	// mouse moving
	virtual void mouseMove(Position mousePos);
	// mouse moving with buttons pressed (drag)
	virtual void mousePressMove(Position mousePos);
	// keyboard key press
	virtual void keyPress(unsigned char key, Position mousePos);
	// keyboard special key press (F1-F12, Arrows, etc.)
	virtual void keyPressSpecial(int key, Position mousePos);

private:

	// int;
};

#endif
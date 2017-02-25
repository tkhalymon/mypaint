#ifndef __PALETTE_HPP__
#define __PALETTE_HPP__

#include <GL/glut.h>

#include "../window/window.hpp"

class Palette : public Window
{
public:
	Palette(int width, int height, const char* title);
	~Palette();
	
	// rendering function
	virtual void display();
	// mouse button pressing
	virtual void mousePress(int button, int state, Vertex mousePos);
	// mouse moving
	virtual void mouseMove(Vertex mousePos);
	// mouse moving with buttons pressed (drag)
	virtual void mousePressMove(Vertex mousePos);
	// keyboard key press
	virtual void keyPress(unsigned char key, Vertex mousePos);
	// keyboard special key press (F1-F12, Arrows, etc.)
	virtual void keyPressSpecial(int key, Vertex mousePos);

private:

};

#endif
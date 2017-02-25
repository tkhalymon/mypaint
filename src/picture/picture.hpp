#ifndef __PICTURE_HPP__
#define __PICTURE_HPP__

#include <vector>
#include <memory>
#include <GL/glut.h>

#include "../window/window.hpp"

// all figures
#include "graphics/line.hpp"
#include "graphics/pencil.hpp"
#include "graphics/ellipse.hpp"

// for action history
#include "actions/action.hpp"

using std::vector;
using std::shared_ptr;
using std::make_shared;

class Picture : public Window
{
public:
	// window size and title
	Picture(int width, int height, const char* title);
	~Picture();

	// void saveState();

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
	// calls when user changes window size
	virtual void reshape (int newWidth, int newHeight);

	bool undo();

	bool redo();

private:

	vector<shared_ptr<Figure>> figures;
	vector<Action> actions;
	shared_ptr<Color> activeColor;
	int lineWidth;
};

#endif // __PICTURE_HPP__
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
#include "graphics/rectangle.hpp"

// for action history
#include "actions/action.hpp"

using std::vector;
using std::shared_ptr;
using std::make_shared;

class Picture : public Window
{
public:
	// window size and title
	Picture(const int& width, const int& height, const char* title);
	~Picture();

	// void saveState();

	// rendering function
	void display();
	// mouse button pressing
	void mousePress(const int& button, const int& state, const Vertex& mousePos);
	// mouse moving
	void mouseMove(const Vertex& mousePos);
	// mouse moving with buttons pressed (drag)
	void mousePressMove(const Vertex& mousePos);
	// keyboard key press
	void keyPress(unsigned char key, const Vertex& mousePos);
	// keyboard special key press (F1-F12, Arrows, etc.)
	void keyPressSpecial(const int& key, const Vertex& mousePos);
	// calls when user changes window size
	void reshape (const int& newWidth, const int& newHeight);
	// undo last action
	bool undo();
	// undo last undo
	bool redo();
	// shared pointer to color for palette
	shared_ptr<Color> colorPtr();

private:

	// all rendered figures
	vector<shared_ptr<Figure>> figures;
	// vector of actions
	vector<shared_ptr<Action>> actions;
	// vector of undone actions (used to revert undo actions)
	vector<shared_ptr<Action>> undoneActs;
	// current drawing color
	shared_ptr<Color> activeColor;
	// current line width
	int lineWidth;
};

#endif // __PICTURE_HPP__
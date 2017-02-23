#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

// GLUT (OpenGL header)
#include <GL/glut.h>
#include <map>
#include <string>

#include "tools/vertex.hpp"
#include "tools/size2d.hpp"

using std::string;
using std::map;

class Window;

/*
	GLUT window abstract class

	Callbacks duplicated because it's possible to pass
	only static methods to GLUT.
*/

class Window
{
public:
	// Window constructor: window size (x; y) and title
	Window(int width, int height, const char* title);
	virtual ~Window();

	// ### Derived classes callbacks ###
	// rendering function
	virtual void display() = 0;

	// ### mouse and keyboard event handlers ###
	// mouse button pressing
	virtual void mousePress(int button, int state, Vertex mousePos) = 0;
	// mouse moving
	virtual void mouseMove(Vertex mousePos) = 0;
	// mouse moving with buttons pressed (drag)
	virtual void mousePressMove(Vertex mousePos) = 0;
	// keyboard key press
	virtual void keyPress(unsigned char key, Vertex mousePos) = 0;
	// keyboard special key press (F1-F12, Arrows, etc.)
	virtual void keyPressSpecial(int key, Vertex mousePos) = 0;
	// set window background
	void setBgColor(double red, double green, double blue);

protected:

	// initialize GLUT
	static int Init();

	// initialization status
	static bool initialized;
	
	// global GLUT callbacks
	static void glutDisplay();
	// button {left, right, middle}, state {pressed, released}, (x, y) - mouse position
	static void glutMousePress(int button, int state, int x, int y);
	// (x, y) - mouse position
	static void glutMouseMove(int x, int y);
	// (x, y) - mouse position
	static void glutMousePressMove(int x, int y);
	// key - character generated by keyboard, (x, y) - mouse position
	static void glutKeyPress(unsigned char key, int x, int y);
	// key - one of special keys (defined as GLUT_KEY_{name})
	static void glutKeyPressSpecial(int key, int x, int y);

private:

	// list of all existing windows (int is a GLUT window ID)
	static map<int, Window*> windows;

	// window ID
	int id;

	// window size
	Size2d size;
};

#endif // __WINDOW_HPP__
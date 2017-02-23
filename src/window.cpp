#include "window.hpp"

// initialize static fields of Window
bool Window::initialized = Window::Init();
// 
map<int, Window*> Window::windows;

int Window::Init()
{
	// passing no arguments
	int argc = 0;
	// global GLUT initialization
	glutInit(&argc, NULL);
	// enable double buffering and RGB color scheme
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	// set GLUT callbacks
	glutDisplayFunc(glutDisplay);
	glutMouseFunc(glutMousePress);
	glutPassiveMotionFunc(glutMouseMove);
	glutMotionFunc(glutMousePressMove);
	glutKeyboardFunc(glutKeyPress);
	glutSpecialFunc(glutKeyPressSpecial);
	return 0;
}

Window::Window(int width, int height, const char* title)
{
	// set window size
	glutInitWindowSize(width, height);
	// create window and get it's ID
	id = glutCreateWindow(title);
	// reset matrix to default state
	glLoadIdentity();
	// set coordinate system form left to right by X and from top to bottom by Y
	glOrtho(0, width, height, 0, 0, 1);
	// set current matrix
	glMatrixMode(GL_MODELVIEW);
	// write to windows list
	windows.insert(std::pair<int, Window*>(id, this));
	// set window background color
	glClearColor(1, 1, 1, 1);
	// clear window
	glClear(GL_COLOR_BUFFER_BIT);
	// write changes to graphic buffer
	glFlush();
}

Window::~Window()
{
	// remove window from list
	windows.erase(windows.find(id));
}

/*
	Each static method calls a current window method,
	passing arguments in more convenient form, if possible
	(such as Position instead of "int x, int y").

	There is no check for window existing, because current window
	is certainly in list (see constructor and destructor).
*/

void Window::glutDisplay()
{
	windows[glutGetWindow()]->glutDisplay();
}

void Window::glutMousePress(int button, int state, int x, int y)
{
	windows[glutGetWindow()]->mousePress(button, state, Position(x, y));
}

void Window::glutMouseMove(int x, int y)
{
	windows[glutGetWindow()]->mouseMove(Position(x, y));
}

void Window::glutMousePressMove(int x, int y)
{
	windows[glutGetWindow()]->mousePressMove(Position(x, y));
}

void Window::glutKeyPress(unsigned char key, int x, int y)
{
	windows[glutGetWindow()]->keyPress(key, Position(x, y));
}

void Window::glutKeyPressSpecial(int key, int x, int y)
{
	windows[glutGetWindow()]->keyPressSpecial(key, Position(x, y));
}

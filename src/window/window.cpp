#include "window.hpp"

// initialize static fields of Window
bool Window::initialized = Window::Init();
// 
map<int, Window*> Window::windows;

bool Window::Init()
{
	if (!initialized)
	{
		// passing no arguments
		int argc = 0;
		// global GLUT initialization
		glutInit(&argc, NULL);
		// enable single buffering and RGB color scheme
		glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	}
	return true;
}

Window::Window(int width, int height, const char* title) : width(width), height(height)
{
	// set window size
	glutInitWindowSize(width, height);
	// create window and get it's ID
	id = glutCreateWindow(title);
	// set current matrix
	glMatrixMode(GL_MODELVIEW);
	// reset matrix to default state
	glLoadIdentity();
	// set coordinate system form left to right by X and from top to bottom by Y
	glOrtho(1, width, height, 1, 0, 1);
	// set window background color to black
	glClearColor(0, 0, 0, 1);
	// set GLUT callbacks
	glutDisplayFunc(glutDisplay);
	glutMouseFunc(glutMousePress);
	glutPassiveMotionFunc(glutMouseMove);
	glutMotionFunc(glutMousePressMove);
	glutKeyboardFunc(glutKeyPress);
	glutSpecialFunc(glutKeyPressSpecial);
	glutReshapeFunc(glutReshape);
	// clear window
	glClear(GL_COLOR_BUFFER_BIT);
	// write changes to graphic buffer
	glFlush();
	// write to windows list
	windows.insert(std::pair<int, Window*>(id, this));
}

Window::~Window()
{
	// remove window from list
	windows.erase(windows.find(id));
}

void Window::setBgColor(float red, float green, float blue)
{
	// RGB scheme, 1 is alpha channel
	glClearColor(red, green, blue, 1);
}

void Window::setMinSize(int width, int height)
{
	minWidth = width;
	minHeight = height;
}

/*
	Each static method calls a current window method,
	passing arguments in more convenient form, if possible
	(such as Vertex instead of "int x, int y").

	There is no check for window existing, because current window
	is certainly in list (see constructor and destructor).
*/

void Window::glutDisplay()
{
	windows[glutGetWindow()]->display();
}

void Window::glutMousePress(int button, int state, int x, int y)
{
	windows[glutGetWindow()]->mousePress(button, state, Vertex(x, y));
}

void Window::glutMouseMove(int x, int y)
{
	windows[glutGetWindow()]->mouseMove(Vertex(x, y));
}

void Window::glutMousePressMove(int x, int y)
{
	windows[glutGetWindow()]->mousePressMove(Vertex(x, y));
}

void Window::glutKeyPress(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		glutDestroyWindow(glutGetWindow());
		exit(0);
	}
	// windows.erase(glutGetWindow());
	windows[glutGetWindow()]->keyPress(key, Vertex(x, y));
}

void Window::glutKeyPressSpecial(int key, int x, int y)
{
	windows[glutGetWindow()]->keyPressSpecial(key, Vertex(x, y));
}

void Window::glutReshape(int width, int height)
{
	windows[glutGetWindow()]->reshape(width, height);
}

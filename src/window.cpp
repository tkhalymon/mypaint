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
	// enable single buffering and RGB color scheme
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	return 0;
}

Window::Window(int width, int height, const char* title) : size(width, height)
{
	// set window size
	glutInitWindowSize(size.width(), size.height());
	// create window and get it's ID
	id = glutCreateWindow(title);
	// set current matrix
	glMatrixMode(GL_MODELVIEW);
	// reset matrix to default state
	glLoadIdentity();
	// set coordinate system form left to right by X and from top to bottom by Y
	glOrtho(0, size.width(), size.height(), 0, 0, 1);
	// set window background color
	glClearColor(0.3, 0.3, 0.3, 1);
	// set GLUT callbacks
	glutDisplayFunc(glutDisplay);
	glutMouseFunc(glutMousePress);
	glutPassiveMotionFunc(glutMouseMove);
	glutMotionFunc(glutMousePressMove);
	glutKeyboardFunc(glutKeyPress);
	glutSpecialFunc(glutKeyPressSpecial);
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

void Window::setBgColor(double red, double green, double blue)
{
	glClearColor(red, green, blue, 1);
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
	if (key == 27) exit(0);
	windows[glutGetWindow()]->keyPress(key, Vertex(x, y));
}

void Window::glutKeyPressSpecial(int key, int x, int y)
{
	windows[glutGetWindow()]->keyPressSpecial(key, Vertex(x, y));
}

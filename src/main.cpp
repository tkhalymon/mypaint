#include <GL/glut.h>

#include "palette/palette.hpp"

#include "picture/picture.hpp"

int main(int argc, char *argv[])
{
	// create picture window
	Picture picture(640, 480, "My Paint");
	// set white background color
	picture.setBgColor(1, 1, 1);
	// create palette window
	Palette palette(300, 230, "Palette", picture.colorPtr());
	// enter GLUT main loop - start callbacks and rendering
	glutMainLoop();
	return 0;
}

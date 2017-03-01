#include <GL/glut.h>

#include "palette/palette.hpp"

#include "picture/picture.hpp"

#include "toolbox/tools.hpp"

int main(int argc, char *argv[])
{
	// create picture window
	Picture picture(640, 480, "My Paint");
	// set white background color
	picture.setBgColor(1, 1, 1);
	// create palette window
	Palette palette(300, 235, "Palette", picture.colorPtr());
	// dark gray
	picture.setBgColor(0.1, 0.1, 0.1);

	// Tools tools(100, 400, "Tools", picture.lineWidthPtr());
	// enter GLUT main loop - start callbacks and rendering
	glutMainLoop();
	return 0;
}

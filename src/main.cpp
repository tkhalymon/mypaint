#include <GL/glut.h>

#include "palette/palette.hpp"

#include "picture/picture.hpp"

int main(int argc, char *argv[])
{
	Picture picture(640, 480, "My Paint");
	// Palette palette(640, 480, "Palette");
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

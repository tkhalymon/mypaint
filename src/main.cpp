#include <GL/glut.h>

#include "palette/palette.hpp"

#include "picture/picture.hpp"

int main(int argc, char *argv[])
{
	Picture picture(640, 480, "My Paint");
	picture.setBgColor(1, 1, 1);
	Palette palette(300, 230, "Palette", picture.colorPtr());
	glutMainLoop();
	return 0;
}

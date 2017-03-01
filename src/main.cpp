#include <GL/glut.h>

#include "palette/palette.hpp"
#include "picture/picture.hpp"
#include "toolbox/tools.hpp"

int main(int argc, char *argv[])
{
	// create picture window
	shared_ptr<Picture> picture = make_shared<Picture>(640, 480, "My Paint");
	// create palette window
	Palette palette(300, 235, "Palette", picture->colorPtr());
	// tools window
	Tools tools(70, 400, "Tools", picture);
	// enter GLUT main loop - start callbacks and rendering
	glutMainLoop();
	return 0;
}

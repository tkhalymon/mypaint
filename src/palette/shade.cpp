#include "shade.hpp"

const double Shade::colors[4][3] = 
{
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},
	{1, 0, 0}
};

Shade::Shade(shared_ptr<int> width, int height, int offset) : Toolbox (width, height, offset)
{
	// default color is red
	color = make_shared<Color>(1, 0, 0);
}

Shade::~Shade()
{

}

bool Shade::click (Vertex mouse)
{
	// check if mouse is inside the toolbox
	if (mouse.x() >= padding && mouse.x() < *width - padding
	    && mouse.y() >= offset + padding && mouse.y() < offset + padding + height)
	{
		// set value
		value = mouse.x() - padding;
		// get pointed pixel color
		unsigned char pixels[3];
		glReadPixels(mouse.x(), glutGet(GLUT_WINDOW_WIDTH) - mouse.y(), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
		// color is returned as byte 0..255, so divide by 255. (floating point)
		*color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
		// toolbox clicked
		return true;
	}
	else
	{
		// toolbox not clicked
		return false;
	}
}

void Shade::render()
{
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 4; ++i)
	{
		glColor3dv(colors[i]);
		glVertex2i(padding + (*width - padding * 2) * i / 3, offset + padding);
		glVertex2i(padding + (*width - padding * 2) * i / 3, offset + padding + height);
	}
	glEnd();
	renderFrame();
	renderArrow();
}
void Shade::update()
{
	unsigned char pixels[3];
	glReadPixels(padding + value, glutGet(GLUT_WINDOW_HEIGHT) - offset - padding - 2, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	*color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
	glutPostRedisplay();
}

shared_ptr<Color>& Shade::colorPtr()
{
	return color;
}

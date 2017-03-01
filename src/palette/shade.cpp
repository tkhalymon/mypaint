#include "shade.hpp"

// shade scale colors (red, green, blue, red)
const double Shade::colors[4][3] = 
{
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},
	{1, 0, 0}
};

Shade::Shade(shared_ptr<int> width, int height, int offset) : Scale (width, height, offset)
{
	// default shade is red
	color = make_shared<Color>(1, 0, 0);
}

Shade::~Shade()
{}

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
	// draw 3 parts of shade scale by triangles
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 4; ++i)
	{
		// bind color
		glColor3dv(colors[i]);
		// draw 2 vertexes
		glVertex2i(padding + (*width - padding * 2) * i / 3, offset + padding);
		glVertex2i(padding + (*width - padding * 2) * i / 3, offset + padding + height);
	}
	// finish drawing
	glEnd();
	// draw frame
	renderFrame();
	// and current value pointer
	renderArrow();
}

void Shade::update()
{
	// update scale when dependent scale changed
	unsigned char pixels[3];
	glReadPixels(padding + value, glutGet(GLUT_WINDOW_HEIGHT) - offset - padding - 2, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	*color = Color(pixels[0] / 255., pixels[1] / 255., pixels[2] / 255.);
	glutPostRedisplay();
}

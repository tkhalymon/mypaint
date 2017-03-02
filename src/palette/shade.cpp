#include "shade.hpp"

// shade scale colors (red, green, blue, red)
const double Shade::colors[4][3] = 
{
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},
	{1, 0, 0}
};

Shade::Shade(shared_ptr<int> width, int height) : Scale (width, height)
{
	// default shade is red
	color = make_shared<Color>(1, 0, 0);
}

Shade::~Shade()
{}

bool Shade::click (Vertex mouse)
{
	// check if mouse is inside the toolbox
	if (mouse.x() >= 0 && mouse.x() <= *width
	    && mouse.y() >= 0 && mouse.y() <= height)
	{
		// set value
		value = mouse.x() / (double)*width;
		// value = mouse.x();
		update();
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
		glVertex2i((*width) * i / 3, 0);
		glVertex2i((*width) * i / 3, height);
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
	int component = (int)(value * 3.);
	double hardness = (value * 3. - component);
	for (int i = 0; i < 3; ++i)
		(*color)[i] = colors[component][i] * (1 - hardness) + colors[component + 1][i] * hardness;
}

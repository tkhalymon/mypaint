#include "final.hpp"

Final::Final(shared_ptr<int> width, int height, int offset, shared_ptr<Color> c)
		: Toolbox (width, height, offset)
{
	color = c;
	*color = Color (1, 0, 0);
}

Final::~Final()
{

}

bool Final::click (Vertex mouse)
{
	return false;
}

void Final::render()
{
	glBegin(GL_TRIANGLE_STRIP);
	color->bind();
	glVertex2i(padding, offset + padding);
	glVertex2i(padding, offset + padding + height - 1);
	glVertex2i(*width - padding, offset + padding);
	glVertex2i(*width - padding, offset + padding + height - 1);
	glEnd();
	renderFrame();
}

void Final::update()
{

}

shared_ptr<Color>& Final::colorPtr()
{
	return color;
}

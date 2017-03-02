#include "linewidth.hpp"

Linewidth::Linewidth(shared_ptr<int> width, shared_ptr<int> padding, shared_ptr<int> lineWidth) : Toolbox (width, padding), value(lineWidth)
{
	// set line width to 1
	*value = 1;
	height = 15 * 8;
}

Linewidth::~Linewidth()
{

}

void Linewidth::render() const
{
	// render background
	glColor3d(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(*width, 0);
	glVertex2i(*width, height);
	glVertex2i(0, height);
	glEnd();
	
	// gray for selected
	glColor3d(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(0, (*value - 1) * 15);
	glVertex2i(*width, (*value - 1) * 15);
	glVertex2i(*width, (*value) * 15);
	glVertex2i(0, (*value) * 15);
	glEnd();
	
	for (int i = 0; i < 8; ++i)
	{
		
		glLineWidth(i + 1);
		glColor3d(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(10, i * 15 + 7);
		glVertex2i(*width - 10, i * 15 + 7);
		glEnd();
	}
}
bool Linewidth::mouseClick(const Vertex& pos)
{
	// check if mouse is inside toolbox
	if (pos.x() > 0 && pos.x() < *width
		&& pos.y() > 0 && pos.y() < height)
	{
		// set value
		*value = pos.y() / 15 + 1;
		return true;
	}
	else
	{
		return false;
	}
}

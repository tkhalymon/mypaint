#include "linewidth.hpp"

Linewidth::Linewidth(shared_ptr<int> width, shared_ptr<int> lineWidth)
		: Toolbox (width), value(lineWidth)
{
	// set line width to 1
	*value = 1;
	// 8 buttons
	buttonHeight = 15;
	height = buttonHeight * 8;
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
	glVertex2i(0, (*value - 1) * buttonHeight);
	glVertex2i(*width, (*value - 1) * buttonHeight);
	glVertex2i(*width, (*value) * buttonHeight);
	glVertex2i(0, (*value) * buttonHeight);
	glEnd();
	
	for (int i = 0; i < 8; ++i)
	{
		
		glLineWidth(i + 1);
		glColor3d(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(5, (i + 0.5) * buttonHeight);
		glVertex2i(*width - 5, (i + 0.5) * buttonHeight);
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
		*value = pos.y() / buttonHeight + 1;
		return true;
	}
	else
	{
		return false;
	}
}

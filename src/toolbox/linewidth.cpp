#include "linewidth.hpp"

Linewidth::Linewidth(shared_ptr<int> width, shared_ptr<int> lineWidth) : Toolbox (width), value(lineWidth)
{
	*value = 1;
	*height = 20 * 8;
}

Linewidth::~Linewidth()
{

}

void Linewidth::render() const
{
	for (int i = 0; i < 8; ++i)
	{

		if (*value == i + 1)
		{
			glColor3d(0.5, 0.5, 0.5);
			glBegin(GL_QUADS);
			glVertex2i(0, i * 20 + 3);
			glVertex2i(*width, i * 20 + 3);
			glVertex2i(*width, i * 20 + 17);
			glVertex2i(0, i * 20 + 17);
			glEnd();
		}
		glColor3d(0, 0, 0);
		glLineWidth(i + 1);
		glBegin(GL_LINES);
		glVertex2i(10, i * 20 + 10);
		glVertex2i(*width - 10, i * 20 + 10);
		glEnd();
	}
}

bool Linewidth::mouseClick(const Vertex& pos)
{
	if (pos.x() > 0 && pos.x() < *width
		&& pos.y() > 0 && pos.y() < *height)
	{
		// acts
		return true;
	}
	else
	{
		return false;
	}
}

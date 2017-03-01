#include "tools.hpp"

Tools::Tools(const int& width, const int& height, const char* title, shared_ptr<Picture> picture)
		: Window (width, height, title), picture(picture)
{
	padding = make_shared<int>(5);
	toolBoxWidth = make_shared<int>(width - *padding * 2);
	// create toolboxes
	toolboxes.push_back(make_shared<Linewidth>(toolBoxWidth, padding, this->picture->lineWidthPtr()));
	toolboxes.push_back(make_shared<Instrument>(toolBoxWidth, padding, this->picture->instrumentPtr()));

	// calculate toolboxes summary size
	*this->height = *padding;
	for (vector<shared_ptr<Toolbox>>::iterator i = toolboxes.begin(); i != toolboxes.end(); ++i)
	{
		*this->height += (*i)->getHeight() + *padding;
	}
	// set minimal window height
	this->minHeight = *this->height;
	// adjust window height to toolbox sizes
	glutReshapeWindow(*this->width, *this->height);
}

Tools::~Tools()
{}

void Tools::display()
{
	// clear screen
	glClear(GL_COLOR_BUFFER_BIT);
	// save matrix transformations
	glPushMatrix();
	// move matrix down and right (paddings)
	glTranslated(*padding, *padding, 0);
	for (vector<shared_ptr<Toolbox>>::iterator box = toolboxes.begin(); box != toolboxes.end(); ++box)
	{
		// draw toolbox
		(*box)->render();
		// move matrix down to draw next toolbox
		glTranslated(0, (*box)->getHeight() + *padding, 0);
	}
	// revert matrix transformations
	glPopMatrix();
	// swap back and on-screen buffers
	glutSwapBuffers();
}

void Tools::mousePress(const int& button, const int& state, const Vertex& mousePos)
{
	// if mouse left button released
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		// calculate mouse position related to toolbox
		Vertex mouse = mousePos;
		mouse.x(mousePos.x() - *padding);
		mouse.y(mousePos.y() - *padding);
		for (vector<shared_ptr<Toolbox>>::iterator box = toolboxes.begin(); box != toolboxes.end(); ++box)
		{
			// check mouse click
			if ((*box)->mouseClick(mouse))
			{
				break;
			}
			else
			{
				// calculate mouse position related to current toolbox
				mouse.y(mouse.y() - (*box)->getHeight() - *padding);
			}
		}
		glutPostRedisplay();
	}
}

void Tools::reshape(const int& width, const int& height)
{
	// refresh toolboxes width
	*toolBoxWidth = width - *padding * 2;
}

#include "tools.hpp"

Tools::Tools(const int& width, const int& height, const char* title, shared_ptr<Picture> picture)
		: Window (width, height, title), picture(picture)
{
	padding = make_shared<int>(10);
	toolBoxWidth = make_shared<int>(width - *padding * 2);
	// create instrument chose toolbox
	toolboxes.insert(std::pair<Toolbox::Type, shared_ptr<Toolbox>>
		(Toolbox::Type::Instrument, make_shared<Instrument>(toolBoxWidth, this->picture->instrumentPtr())));
	// adjust window height to toolboxes height
	checkHeight();
	// set minimal window height
	this->minHeight = *this->height;
	// adjust window height to toolbox sizes
	glutReshapeWindow(*this->width, *this->height);
}

Tools::~Tools()
{
	toolboxes.clear();
}

void Tools::display()
{
	// clear screen
	glClear(GL_COLOR_BUFFER_BIT);
	// save matrix transformations
	glPushMatrix();
	// move matrix down and right (paddings)
	glTranslated(*padding, *padding, 0);
	for (auto box = toolboxes.begin(); box != toolboxes.end(); ++box)
	{
		// draw toolbox
		box->second->render();
		// move matrix down to draw next toolbox
		glTranslated(0, box->second->getHeight() + *padding, 0);
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
		for (auto box = toolboxes.begin(); box != toolboxes.end(); ++box)
		{
			// check mouse click
			if (box->second->mouseClick(mouse))
			{
				// don't check next toolboxes
				break;
			}
			else
			{
				// calculate mouse position related to current toolbox
				mouse.y(mouse.y() - box->second->getHeight() - *padding);
			}
		}
	}
	// check if any toolboxes should be created or deleted
	checkToolboxes();
	// redraw window
	glutPostRedisplay();
}

void Tools::reshape(const int& width, const int& height)
{
	// refresh toolboxes width
	*toolBoxWidth = width - *padding * 2;
}

void Tools::checkHeight()
{
	// calculate summary toolboxes width + paddings
	*this->height = *padding;
	for (auto i = toolboxes.begin(); i != toolboxes.end(); ++i)
	{
		*this->height += i->second->getHeight() + *padding;
	}
	// set minimal window height
	this->minHeight = *this->height;
	// set new window size
	glutReshapeWindow(*this->width, *this->height);
}

void Tools::checkToolboxes()
{
	// if instrument is pencil and linewidth toolbox exists
	if (*picture->instrumentPtr() == Figure::Type::Pencil && toolboxes.find(Toolbox::Type::Linewidth) != toolboxes.end())
	{
		// remove line width toolbox
		toolboxes.erase(Toolbox::Type::Linewidth);
		// resize window
		checkHeight();
	}
	// if instrument is not pencil and linewidth toolbox doesn't exist
	if (*picture->instrumentPtr() != Figure::Type::Pencil && toolboxes.find(Toolbox::Type::Linewidth) == toolboxes.end())
	{
		// add line width toolbox
		toolboxes.insert(std::pair<Toolbox::Type, shared_ptr<Toolbox>>
			(Toolbox::Type::Linewidth, make_shared<Linewidth>(toolBoxWidth, this->picture->lineWidthPtr())));
		// resize window
		checkHeight();
	}	
}
#include "picture.hpp"

Picture::Picture(const int& width, const int& height, const char* title)
		: Window (width, height, title)
{
	// set white background color
	setBgColor(1, 1, 1);
	if (activeColor.use_count() == 0)
	{
		// default color - black
		activeColor = make_shared<Color>(0, 0, 0);
	}
	// default line width
	if (lineWidth.use_count() == 0)
	{
		lineWidth = make_shared<int>(1);
	}
	// default instrument
	if (instrument.use_count() == 0)
	{
		instrument = make_shared<int>(1);
	}
}

Picture::~Picture()
{}

void Picture::display()
{
	// clear screen
	glClear(GL_COLOR_BUFFER_BIT);
	// render all figures
	for (std::vector<shared_ptr<Figure>>::iterator i = figures.begin(); i != figures.end(); ++i)
	{
		(*i)->render();
	}
	// move back buffer to screen
	glutSwapBuffers();
}

void Picture::mousePress(const int& button, const int& state, const Vertex& mousePos)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			switch (*instrument)
			{
			case 1:
				figures.push_back(make_shared<Pencil>(mousePos, *activeColor));
				break;
			case 2:
				figures.push_back(make_shared<Line>(mousePos, *activeColor, *lineWidth));
				break;
			case 3:
				figures.push_back(make_shared<Ellipse>(mousePos, *activeColor, *lineWidth));
				break;
			case 4:
				figures.push_back(make_shared<Rectangle>(mousePos, *activeColor, *lineWidth));
				break;
			}
		}
		actions.push_back(make_shared<Action>(figures.back(), Action::Type::Create));
		undoneActs.clear();
	}
	else
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			if (!figures.empty())
			{
				figures.back()->finish();
			}
		}
	}
}

void Picture::mouseMove(const Vertex& mousePos)
{
	// current mouse position can be shown here
}

void Picture::mousePressMove(const Vertex& mousePos)
{
	// figure may be deleted in process of creation, so check it figure exists
	if (!figures.empty() && !figures.back()->finished())
	{
		// submit mouse move action
		figures.back()->mouseMoved(mousePos);
	}
	// redraw screen
	glutPostRedisplay();
}

void Picture::keyPress(unsigned char key, const Vertex& mousePos)
{
	int modifiers = glutGetModifiers();
	bool ctrl = modifiers & GLUT_ACTIVE_CTRL;
	// bool alt = modifiers & GLUT_ACTIVE_ALT;
	// bool shift = modifiers & GLUT_ACTIVE_SHIFT;
	switch(key)
	{
	case 26: // ctrl-z
		if (ctrl) undo();
		break;
	case 25: // ctrl-y
		if (ctrl) redo();
		break;
	}
}

void Picture::reshape (const int& newWidht, const int& newHeight)
{

}

bool Picture::undo()
{
	// if no actions was performed
	if (actions.empty())
	{
		return false;
	}
	else
	{
		// write undone action to vector
		undoneActs.push_back(actions.back());
		switch (actions.back()->type())
		{
		case Action::Type::Create:
			// remove figure
			if (!figures.empty())
			{
				figures.pop_back();
			}
			break;
		case Action::Type::Delete:
			// add deleted figure to figures vector
			figures.push_back(actions.back()->figure());
			break;
		};
		// remove action from done actions vector
		actions.pop_back();
		// redraw
		glutPostRedisplay();
		return true;

	}
}

bool Picture::redo()
{
	if (undoneActs.empty())
	{
		return false;
	}
	else
	{
		figures.push_back(undoneActs.back()->figure());
		actions.push_back(undoneActs.back());
		undoneActs.pop_back();
		glutPostRedisplay();
		return true;
	}
}

shared_ptr<Color>& Picture::colorPtr()
{
	return activeColor;
}

shared_ptr<int> Picture::lineWidthPtr()
{
	return lineWidth;
}

shared_ptr<int> Picture::instrumentPtr()
{
	return instrument;
}

#include "picture.hpp"

Picture::Picture(const int& width, const int& height, const char* title) : Window (width, height, title)
{
	lineWidth = 5;
	activeColor = make_shared<Color>(0, 0, 0);
}

Picture::~Picture()
{

}

void Picture::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (std::vector<shared_ptr<Figure>>::iterator i = figures.begin(); i != figures.end(); ++i)
	{
		(*i)->render();
	}
	glutSwapBuffers();
}

void Picture::mousePress(const int& button, const int& state, const Vertex& mousePos)
{
	if (state == GLUT_DOWN)
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			figures.push_back(make_shared<Pencil>(mousePos, *activeColor, lineWidth));
			break;
		case GLUT_MIDDLE_BUTTON:
			// figures.push_back(make_shared<Ellipse>(mousePos, *activeColor, lineWidth));
			figures.push_back(make_shared<Rectangle>(mousePos, *activeColor, lineWidth));
			break;
		case GLUT_RIGHT_BUTTON:
			figures.push_back(make_shared<Line>(mousePos, *activeColor, lineWidth));
			break;
		default:
			break;
		}
		actions.push_back(make_shared<Action>(figures.back(), Action::Type::Create));
		undoneActs.clear();
	}
	// glutPostRedisplay();
}

void Picture::mouseMove(const Vertex& mousePos)
{

}

void Picture::mousePressMove(const Vertex& mousePos)
{
	figures.back()->mouseMoved(mousePos);
	glutPostRedisplay();
	// glutSwapBuffers();
}

void Picture::keyPress(unsigned char key, const Vertex& mousePos)
{
	switch(key)
	{
	case 8: // Backspace
		undo();
		break;
	case 13:
		redo();
		break;
	}
}

void Picture::keyPressSpecial(const int& key, const Vertex& mousePos)
{
	
}

void Picture::reshape (const int& newWidht, const int& newHeight)
{
	// check if new size not less then minimal
	// Size2d size(width, height);
	// if (newSize.width() < minSize.width())
	// {
	// 	newSize.setWidth(minSize.width());
	// }
	// if (newSize.height() < minSize.height())
	// {
	// 	newSize.setHeight(minSize.height());
	// }
	// if (newSize == Size2d(newSize.width(), newSize.height()))
	// {
	// 	glutReshapeWindow(newSize.width(), newSize.height());
	// }
}

bool Picture::undo()
{
	if (actions.empty())
	{
		return false;
	}
	else
	{
		switch (actions.back()->type())
		{
		case Action::Type::Create:
			undoneActs.push_back(actions.back());
			figures.pop_back();
			actions.pop_back();
			break;
		case Action::Type::Delete:
			undoneActs.push_back(actions.back());
			figures.push_back(actions.back()->figure());
			actions.pop_back();
			break;
		};
		glutPostRedisplay();
		return true;

	}
		glutSetCursor(GLUT_CURSOR_CYCLE);
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

shared_ptr<Color> Picture::colorPtr()
{
	return activeColor;
}
#include "picture.hpp"

Picture::Picture(int width, int height, const char* title) : Window (width, height, title)
{
	lineWidth = 2;
	activeColor = make_shared<Color>(1, 1, 1);
}

Picture::~Picture()
{

}

// void Picture::saveState()
// {
// 	unsigned char* data = new unsigned char[3]; // rm -rf
// 	// glReadPixels(x - 1, glutGet(GLUT_WINDOW_HEIGHT) - y, 2, 2, GL_RGBA, GL_UNSIGNED_BYTE, data); // rm -rf
// 	// cerr << "(" << x << ":" << y << ") "; // rm -rf
// 	for (int i = 0; i < 4; ++i) // rm -rf
// 	{ // rm -rf
// 		for (int k = 0; k < 4; ++k) // rm -rf
// 		{ // rm -rf
// 			cerr << (int)data[k + i * 4] << " "; // rm -rf
// 		} // rm -rf
// 		cerr << "\n"; // rm -rf
// 	} // rm -rf
// 	// Line by line // rm -rf
// 	// 7  8  9 // rm -rf
// 	// 4  5  6 // rm -rf
// 	// 1  2  3 // rm -rf
// }

void Picture::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (std::vector<shared_ptr<Figure>>::iterator i = figures.begin(); i != figures.end(); ++i)
	{
		(*i)->render();
	}
	glBegin(GL_POINTS);
	for (int i = -1; i <= height  * 3; ++i)
	{
		glVertex2d(100 + (i % 3) * 6, i);
	}
	glVertex2d(50, 1);
	glVertex2d(50, 480);
	glEnd();
	glFlush();
}

void Picture::mousePress(int button, int state, Vertex mousePos)
{
	// glutPostRedisplay();
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			figures.push_back(make_shared<Pencil>(mousePos, *activeColor, lineWidth));
		}
		if (button == GLUT_MIDDLE_BUTTON)
		{
			figures.push_back(make_shared<Ellipse>(mousePos, *activeColor, lineWidth));
		}
		if (button == GLUT_RIGHT_BUTTON)
		{
			figures.push_back(make_shared<Line>(mousePos, *activeColor, lineWidth));
		}
	}
	// display();
}

void Picture::mouseMove(Vertex mousePos)
{

}

void Picture::mousePressMove(Vertex mousePos)
{
	figures.back()->mouseVertex(mousePos);
	glutPostRedisplay();
}

void Picture::keyPress(unsigned char key, Vertex mousePos)
{
	switch(key)
	{
	case 8: // Backspace
		if (figures.size() > 0)
		{
			figures.pop_back();
			glutPostRedisplay();
		}
		break;
	}
}

void Picture::keyPressSpecial(int key, Vertex mousePos)
{
	
}

void Picture::reshape (int newWidht, int newHeight)
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
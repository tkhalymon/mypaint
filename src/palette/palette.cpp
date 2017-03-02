#include "palette.hpp"

Palette::Palette(int width, int height, const char* title, shared_ptr<Color>& color)
	: Window(width, height, title), color(color)
{
	// color = make_shared<Color>(0, 0, 0);
	padding = 15;
	scaleWidth = make_shared<int>(width - 2 * padding);
	// create all scales
	// Shade scale
	scales.push_back(make_shared<Shade>(scaleWidth, 50));
	// Brightness scale
	scales.push_back(make_shared<Brightness>(scaleWidth, 30, scales.back()->colorPtr()));
	// Lightness scale
	scales.push_back(make_shared<Lightness>(scaleWidth, 30, scales.back()->colorPtr()));
	// and a resulting color
	scales.push_back(make_shared<Final>(scaleWidth, 50, scales.back()->colorPtr()));
	color = scales.back()->colorPtr();
	minHeight = 235;
	minWidth = 200;
}

Palette::~Palette()
{}

void Palette::display()
{
	// clear screen
	glClear(GL_COLOR_BUFFER_BIT);
	// 
	glPushMatrix();
	glTranslated(padding, padding, 0);
	// render all scales
	for (vector<shared_ptr<Scale>>::iterator i = scales.begin(); i != scales.end(); ++i)
	{
		(*i)->render();
		glTranslated(0, padding + (*i)->getHeight(), 0);
	}
	// 
	glPopMatrix();
	// swap back and front buffer (drawing buffer and on-screen buffer)
	glutSwapBuffers();
}

void Palette::mousePress(const int& button, const int& state, const Vertex& mousePos)
{
	// if button is pressed down
	if (button == GLUT_LEFT_BUTTON)
	{
		Vertex mouse = mousePos;
		mouse.set(mouse.x() - padding, mouse.y() - padding);
		for (auto i = scales.begin(); i != scales.end(); ++i)
		{
			if ((*i)->click(mouse))
			{
				// redraw screen
				glutPostRedisplay();
				// don't check next
				break;
			}
			// move mouse to next scale
			mouse.y(mouse.y() - (*i)->getHeight() - padding);
		}
		// update all scales, except last (it's updated automatically)
		for (auto i = scales.begin(); i != scales.end(); ++i)
		{
			(*i)->update();
		}
		// redraw screen
		glutPostRedisplay();
	}
}

void Palette::mousePressMove(const Vertex& mousePos)
{
	Vertex mouse = mousePos;
	mouse.set(mouse.x() - padding, mouse.y() - padding);
	for (auto i = scales.begin(); i != scales.end(); ++i)
	{
		if ((*i)->click(mouse))
		{
			// redraw screen
			glutPostRedisplay();
			// don't check next
			break;
		}
		mouse.y(mouse.y() - (*i)->getHeight() - padding);
	}
	// update all scales, except last (it's updated automatically)
	for (auto i = scales.begin(); i != scales.end(); ++i)
	{
		(*i)->update();
	}
	// redraw screen
	glutPostRedisplay();
}

void Palette::reshape(const int& width, const int& height)
{
	// refresh scales width
	*scaleWidth = width - 2 * padding;
}

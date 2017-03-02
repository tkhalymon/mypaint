#include "palette.hpp"

Palette::Palette(int width, int height, const char* title, shared_ptr<Color> color)
	: Window(width, height, title), color(color)
{
	// create all scales
	// Shade scale
	scales.push_back(make_shared<Shade>(this->width, 50, 0));
	int offset = scales.back()->getOffset() + scales.back()->getHeight();
	// Brightness scale
	scales.push_back(make_shared<Brightness>(this->width, 30, offset, scales.back()->colorPtr()));
	offset = scales.back()->getOffset() + scales.back()->getHeight();
	// Lightness scale
	scales.push_back(make_shared<Lightness>(this->width, 30, offset, scales.back()->colorPtr(), color));
	offset = scales.back()->getOffset() + scales.back()->getHeight();
	// and a resulting color
	scales.push_back(make_shared<Final>(this->width, 50, offset, color));
	minHeight = 235;
	minWidth = 200;
}

Palette::~Palette()
{}

void Palette::display()
{
	// clear screen
	glClear(GL_COLOR_BUFFER_BIT);
	// render all scales
	for (vector<shared_ptr<Scale>>::iterator i = scales.begin(); i != scales.end(); ++i)
	{
		(*i)->render();
	}
	// swap back and front buffer (drawing buffer and on-screen buffer)
	glutSwapBuffers();
}

void Palette::mousePress(const int& button, const int& state, const Vertex& mousePos)
{
	// if button is pressed down
	if (button == GLUT_LEFT_BUTTON)
	{
		for (vector<shared_ptr<Scale>>::iterator i = scales.begin(); i != scales.end(); ++i)
		{
			if ((*i)->click(mousePos))
			{
				// redraw screen
				glutPostRedisplay();
				// don't check next
				break;
			}
		}
		// update all scales, except last (it's updated automatically)
		for (auto i = scales.begin(); i != --scales.end(); ++i)
		{
			(*i)->update();
		}
		// redraw screen
		glutPostRedisplay();
	}
}

void Palette::mousePressMove(const Vertex& mousePos)
{
	for (vector<shared_ptr<Scale>>::iterator i = scales.begin(); i != scales.end(); ++i)
	{
		if ((*i)->click(mousePos))
		{
			// redraw screen
			glutPostRedisplay();
			// don't check next
			break;
		}
	}
	// update all scales, except last (it's updated automatically)
	for (auto i = scales.begin(); i != --scales.end(); ++i)
	{
		(*i)->update();
	}
	// redraw screen
	glutPostRedisplay();
}

void Palette::reshape(const int& width, const int& height)
{

}

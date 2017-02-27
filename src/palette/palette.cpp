#include "palette.hpp"

Palette::Palette(int width, int height, const char* title, shared_ptr<Color> color)
				: Window(width, height, title), color(color)
{
	toolboxes.push_back(make_shared<Shade>(this->width, 50, 0));
	int offset = toolboxes.back()->getOffset() + toolboxes.back()->getHeight();
	toolboxes.push_back(make_shared<Brightness>(this->width, 30, offset, toolboxes.back()->colorPtr()));
	offset = toolboxes.back()->getOffset() + toolboxes.back()->getHeight();
	toolboxes.push_back(make_shared<Lightness>(this->width, 30, offset, toolboxes.back()->colorPtr(), color));
	offset = toolboxes.back()->getOffset() + toolboxes.back()->getHeight();
	toolboxes.push_back(make_shared<Final>(this->width, 30, offset, color));
}

Palette::~Palette()
{

}

void Palette::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (vector<shared_ptr<Toolbox>>::iterator i = toolboxes.begin(); i != toolboxes.end(); ++i)
	{
		(*i)->render();
	}
	color->bind();
	glutSwapBuffers();
}

void Palette::mousePress(const int& button, const int& state, const Vertex& mousePos)
{
	if (state == GLUT_DOWN)
	{
		for (vector<shared_ptr<Toolbox>>::iterator i = toolboxes.begin(); i != toolboxes.end(); ++i)
		{
			if ((*i)->click(mousePos))
			{
				glutPostRedisplay();
				// don't check next
				break;
			}
		}
		for (vector<shared_ptr<Toolbox>>::iterator i = toolboxes.begin(); i != toolboxes.end(); ++i)
		{
			(*i)->update();
		}	
	}
	glutPostRedisplay();
}

void Palette::mouseMove(const Vertex& mousePos)
{

}

void Palette::mousePressMove(const Vertex& mousePos)
{
	for (vector<shared_ptr<Toolbox>>::iterator i = toolboxes.begin(); i != toolboxes.end(); ++i)
	{
		if ((*i)->click(mousePos))
		{
			glutPostRedisplay();
			// don't check next
			// i++;
			break;
		}
	}
	for (vector<shared_ptr<Toolbox>>::iterator i = toolboxes.begin(); i != toolboxes.end(); ++i)
	{
		(*i)->update();
	}
	glutPostRedisplay();
}

void Palette::keyPress(unsigned char key, const Vertex& mousePos)
{

}

void Palette::keyPressSpecial(const int& key, const Vertex& mousePos)
{

}

void Palette::reshape(const int& width, const int& height)
{

}

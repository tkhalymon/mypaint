#include "palette.hpp"

Palette::Palette(int width, int height, const char* title) : Window(width, height, title)
{
	
}

Palette::~Palette()
{

}

void Palette::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// render
	glFlush();
}

void Palette::mousePress(int button, int state, Position mousePos)
{

}

void Palette::mouseMove(Position mousePos)
{

}

void Palette::mousePressMove(Position mousePos)
{

}

void Palette::keyPress(unsigned char key, Position mousePos)
{

}

void Palette::keyPressSpecial(int key, Position mousePos)
{

}

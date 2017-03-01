#include "tools.hpp"

Tools::Tools(const int& width, const int& height, const char* title, shared_ptr<int> lineWidth)
		: Window (width, height, title)
{
	toolboxes.push_back(make_shared<Linewidth>(this->width, lineWidth));
}

Tools::~Tools()
{

}

void Tools::display()
{

}

void Tools::mousePress(const int& button, const int& state, const Vertex& mousePos)
{

}

void Tools::mousePressMove(const Vertex& mousePos)
{

}

void Tools::reshape(const int& width, const int& height)
{

}

#include "toolbox.hpp"

Toolbox::Toolbox(shared_ptr<int> width) : width(width)
{
	height = make_shared<int>(0);
}

Toolbox::~Toolbox()
{

}

int Toolbox::getHeight()
{
	return *height;
}

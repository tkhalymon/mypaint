#include "toolbox.hpp"

Toolbox::Toolbox(shared_ptr<int> width) : width(width)
{

}

Toolbox::~Toolbox()
{

}

int Toolbox::getHeight()
{
	return height;
}

#include "toolbox.hpp"

Toolbox::Toolbox(shared_ptr<int> width, shared_ptr<int> padding) : width(width), padding(padding)
{

}

Toolbox::~Toolbox()
{

}

int Toolbox::getHeight()
{
	return height;
}

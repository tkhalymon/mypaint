#ifndef __TOOLBOX_HPP__
#define __TOOLBOX_HPP__

#include <memory>

using std::shared_ptr;
using std::make_shared;

class Tools;

#include "../window/window.hpp"
#include "toolbox.hpp"

class Tools : public Window
{
public:
	Tools();
	~Tools();

private:

	int height;

protected:

	shared_ptr<int> width;
};

#endif
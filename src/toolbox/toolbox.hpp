#ifndef __TOOLBOX_HPP__
#define __TOOLBOX_HPP__

#include <memory>

using std::shared_ptr;
using std::make_shared;

class Toolbox;

/*
	class Toolbox

	Toolbox is a part of "Tools" window, used to change current tool,
	line width, or other parameters
*/

class Toolbox
{
public:
	Toolbox();
	~Toolbox();

private:

protected:

	shared_ptr<int> width;
};

#endif
#ifndef __TOOLBOX_TOOLBOX_HPP__
#define __TOOLBOX_TOOLBOX_HPP__

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
using std::make_shared;

class Toolbox;

#include "../graphics/vertex.hpp"

/*
	class Toolbox

	Toolbox is a part of "Tools" window, used to change current tool,
	line width, or other parameters
*/

class Toolbox
{
public:
	Toolbox(shared_ptr<int> width);
	~Toolbox();

	virtual bool mouseClick(const Vertex& pos) = 0;
	virtual void render() const = 0;
	int getHeight();

private:

protected:
	shared_ptr<int> height;
	shared_ptr<int> width;
	static int padding;
};

#endif // __TOOLBOX_TOOLBOX_HPP__
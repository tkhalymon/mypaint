#ifndef __TOOLBOX_TOOLBOX_HPP__
#define __TOOLBOX_TOOLBOX_HPP__

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
using std::make_shared;

class Toolbox;

#include "../graphics/vertex.hpp"
#include "../picture/picture.hpp"

/*
	class Toolbox

	Toolbox is a part of "Tools" window, used to change current tool,
	line width, or other parameters
*/

class Toolbox
{
public:
	Toolbox(shared_ptr<int> width, shared_ptr<int> padding);
	~Toolbox();

	virtual bool mouseClick(const Vertex& pos) = 0;
	virtual void render() const = 0;
	int getHeight();

private:

protected:

	int height;
	shared_ptr<int> width;
	shared_ptr<int> padding;
};

#endif // __TOOLBOX_TOOLBOX_HPP__
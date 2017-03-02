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
	enum class Type { Instrument, Linewidth };
	// toolbox width and paddings
	Toolbox(shared_ptr<int> width);
	~Toolbox();
	// mouse click handler
	virtual bool mouseClick(const Vertex& pos) = 0;
	// drawing
	virtual void render() const = 0;
	// toolbox height
	int getHeight();

private:

protected:

	int height;
	shared_ptr<int> width;
};

#endif // __TOOLBOX_TOOLBOX_HPP__
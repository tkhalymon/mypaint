#ifndef __TOOLBOX_LINEWIDTH_HPP__
#define __TOOLBOX_LINEWIDTH_HPP__

#include <memory>

using std::shared_ptr;
using std::make_shared;

class Linewidth;

#include "toolbox.hpp"

class Linewidth : public Toolbox
{
public:
	// pointer to picture current line width
	Linewidth(shared_ptr<int> width, shared_ptr<int> lineWidth);
	~Linewidth();
	void render() const;
	bool mouseClick(const Vertex& pos);

private:
	// line width value
	shared_ptr<int> value;
	int buttonHeight;
};

#endif // __TOOLBOX_LINEWIDTH_HPP__
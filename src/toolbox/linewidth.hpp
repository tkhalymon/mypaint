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
	Linewidth(shared_ptr<int> width, shared_ptr<int> padding, shared_ptr<int> lineWidth);
	~Linewidth();
	void render() const;
	bool mouseClick(const Vertex& pos);

private:
	shared_ptr<int> value;
};

#endif // __TOOLBOX_LINEWIDTH_HPP__
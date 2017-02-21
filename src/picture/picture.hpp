#ifndef __PICTURE_HPP__
#define __PICTURE_HPP__

#include <vector>
#include <memory>

#include "graphics/figure.hpp"
#include "actions/action.hpp"

using std::vector;
using std::shared_ptr;

class Picture
{
public:
	Picture();
	~Picture();

private:

	vector<shared_ptr<Figure>> figures;
	vector<Action> actions;
};

#endif
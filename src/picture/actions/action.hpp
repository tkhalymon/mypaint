#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include <memory>

using std::shared_ptr;

#include "../graphics/figure.hpp"

class Action
{
public:
	Action();
	~Action();

private:

	shared_ptr<Figure> figure;
};

#endif
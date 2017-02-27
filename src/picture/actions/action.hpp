#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include <memory>

using std::shared_ptr;

#include "../graphics/figure.hpp"

class Action
{
public:
	enum Type { Create, Delete };

	Action(shared_ptr<Figure> pFigure, Type t);
	~Action();

	Type type();

	shared_ptr<Figure> figure();

private:
	// pointer to affected figure
	shared_ptr<Figure> affectedFigure;
	// action type
	Type actType;
};

#endif // __ACTION_HPP__
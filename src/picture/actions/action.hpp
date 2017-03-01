#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include <memory>

using std::shared_ptr;

#include "../../graphics/figure.hpp"

class Action
{
public:
	// action type
	enum Type { Create, Delete };

	Action(shared_ptr<Figure> pFigure, Type t);
	~Action();

	// get action type
	const Type& type() const;
	// get affected figure
	shared_ptr<Figure> figure();

private:
	// pointer to affected figure
	shared_ptr<Figure> affectedFigure;
	// action type
	Type actType;
};

#endif // __ACTION_HPP__
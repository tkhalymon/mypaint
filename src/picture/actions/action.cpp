#include "action.hpp"

Action::Action(shared_ptr<Figure> figure, Type t) : affectedFigure(figure), actType(t)
{

}

Action::~Action()
{

}

Action::Type Action::type()
{
	return actType;
}

shared_ptr<Figure> Action::figure()
{
	return affectedFigure;
}

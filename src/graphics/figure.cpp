#include "figure.hpp"

Figure::Figure(Color color) : color (color), isSelected(false), isFinished(false)
{}

Figure::~Figure()
{}

void Figure::finish()
{
	isFinished = true;
}

bool Figure::finished()
{
	return isFinished;
}

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

int Figure::getTypeId(Figure::Type t)
{
	switch (t)
	{
	case Figure::Type::Pencil:
		return 1;
		break;
	case Figure::Type::Line:
		return 2;
		break;
	case Figure::Type::Ellipse:
		return 3;
		break;
	case Figure::Type::Rectangle:
		return 4;
		break;
	default:
		throw "Unknown element type";
		break;
	}
}

Figure::Type Figure::getTypeById(int id)
{
	switch (id)
	{
	case 1:
		return Figure::Type::Pencil;
		break;
	case 2:
		return Figure::Type::Line;
		break;
	case 3:
		return Figure::Type::Ellipse;
		break;
	case 4:
		return Figure::Type::Rectangle;
		break;
	default:
		throw "Unknown element type";
		break;
	}
}

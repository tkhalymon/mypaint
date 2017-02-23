#include "figure.hpp"

Figure::Figure(Color color, int lineWidth) : color (color), lineWidth(lineWidth)
{}

Figure::~Figure()
{}

void Figure::bindColor()
{
	color.bind();
	glLineWidth(lineWidth);
}

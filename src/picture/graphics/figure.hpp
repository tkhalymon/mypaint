#ifndef __FIGURE_HPP
#define __FIGURE_HPP

class Figure;

#include "vertex.hpp"

class Figure
{
public:
	Figure();
	~Figure();

	virtual void render() = 0;

private:

};

#endif
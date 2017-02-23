#ifndef __PICTURE_HPP__
#define __PICTURE_HPP__

#include <vector>
#include <memory>
#include <GL/glut.h>

#include "graphics/line.hpp"
#include "graphics/vertex.hpp"
#include "graphics/point.hpp"
#include "graphics/ellipse.hpp"

#include "actions/action.hpp"

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::cerr; // rf- rf

class Picture
{
public:
	Picture();
	~Picture();

	void saveState();

	void render();

private:

	int width;
	int height;

	vector<shared_ptr<Figure>> figures;
	vector<Action> actions;
};

#endif
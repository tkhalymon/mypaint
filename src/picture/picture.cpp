#include "picture.hpp"

Picture::Picture()
{
	// figures.push_back(Line(100, 100, 200, 200));
	figures.push_back(make_shared<Line>(Line(100, 100, 200, 200)));
}

Picture::~Picture()
{

}

void Picture::saveState()
{
	unsigned char* data = new unsigned char[3]; // rm -rf
	// glReadPixels(x - 1, glutGet(GLUT_WINDOW_HEIGHT) - y, 2, 2, GL_RGBA, GL_UNSIGNED_BYTE, data); // rm -rf
	// cerr << "(" << x << ":" << y << ") "; // rm -rf
	for (int i = 0; i < 4; ++i) // rm -rf
	{ // rm -rf
		for (int k = 0; k < 4; ++k) // rm -rf
		{ // rm -rf
			cerr << (int)data[k + i * 4] << " "; // rm -rf
		} // rm -rf
		cerr << "\n"; // rm -rf
	} // rm -rf
	// Line by line // rm -rf
	// 7  8  9 // rm -rf
	// 4  5  6 // rm -rf
	// 1  2  3 // rm -rf
}

void Picture::render()
{
	for (vector<shared_ptr<Figure>>::iterator i = figures.begin(); i != figures.end(); ++i)
	{
		(*i)->render();
	}
}

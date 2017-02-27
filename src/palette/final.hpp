#ifndef __FINAL_HPP__
#define __FINAL_HPP__

#include "toolbox.hpp"

// just a toolbox, that shows current color

class Final : public Toolbox
{
public:
	Final(shared_ptr<int> width, int height, int offset, shared_ptr<Color> color);
	~Final();
	bool click(Vertex mouse);
	void render();
	void update();
	shared_ptr<Color>& colorPtr();
};

#endif // __FINAL_HPP__
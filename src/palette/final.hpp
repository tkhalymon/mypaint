#ifndef __FINAL_HPP__
#define __FINAL_HPP__

#include "scale.hpp"

/*
	class Figure

	just a piece, that shows current color
*/

class Final : public Scale
{
public:
	Final(shared_ptr<int> width, int height, int offset, shared_ptr<Color> color);
	~Final();
	
	bool click(Vertex mouse);
	void render();
};

#endif // __FINAL_HPP__
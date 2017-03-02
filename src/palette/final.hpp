#ifndef __PALETTE_FINAL_HPP__
#define __PALETTE_FINAL_HPP__

#include "scale.hpp"

/*
	class Figure

	just a piece, that shows current color
*/

class Final : public Scale
{
public:
	Final(shared_ptr<int> width, int height, shared_ptr<Color> color);
	~Final();
	
	bool click(Vertex mouse);
	void render();
};

#endif // __PALETTE_FINAL_HPP__
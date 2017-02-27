#ifndef __BRIGHTNESS_HPP__
#define __BRIGHTNESS_HPP__

#include "toolbox.hpp"

class Brightness : public Toolbox
{
public:
	// shade is a color, from whitch the scale will start
	Brightness(shared_ptr<int> width, int height, int offset, shared_ptr<Color> shade);
	~Brightness();
	bool click(Vertex mouse);
	void render();
	void update();
	shared_ptr<Color>& colorPtr();

private:
	shared_ptr<Color> lightColor;
};

#endif // __BRIGHTNESS_HPP__
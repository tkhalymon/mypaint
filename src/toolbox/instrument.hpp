#ifndef __TOOLBOX_INSTRUMENT_HPP__
#define __TOOLBOX_INSTRUMENT_HPP__

#include <memory>
#include <math.h>

using std::shared_ptr;
using std::make_shared;

class Instrument;

/*
	class Instrument

	chooses the current drawing instrument
*/

#include "toolbox.hpp"

class Instrument : public Toolbox
{
public:
	Instrument(shared_ptr<int> width, shared_ptr<int> padding, shared_ptr<int> instrument);
	~Instrument();
	void render() const;
	bool mouseClick(const Vertex& pos);

private:
	
	shared_ptr<int> value;
};

#endif // __TOOLBOX_INSTRUMENT_HPP__
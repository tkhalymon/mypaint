#ifndef __POSITION_HPP__
#define __POSITION_HPP__

/*
	class Position

	Used for mouse, graphic object, window position.
*/

struct Position
{
	Position (int x, int y);

	// setters
	void x(int value);
	void y(int value);

	// set both values
	void set (int x, int y);

	// getters
	const int& x() const;
	const int& y() const;

	// convert to array operator
	operator int const* () const;
private:

	// structure data
	int data[2];

	// indexes of elements in array
	static const int x_index;
	static const int y_index;
};

#endif
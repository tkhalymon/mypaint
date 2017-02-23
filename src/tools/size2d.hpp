#ifndef __SIZE2D_HPP__
#define __SIZE2D_HPP__

/*
	class Size2d

	Used for graphic object and window size.
*/

struct Size2d
{
	Size2d (int width, int height);

	// setters
	void width(int value);
	void height(int value);

	// set both values
	void set (int width, int height);

	// getters
	const int& width() const;
	const int& height() const;

	// convert to array operator
	operator int const* () const;
private:

	// structure data
	int data[2];

	// indexes of elements in array
	static const int width_index;
	static const int height_index;
};

#endif // __SIZE2D_HPP__
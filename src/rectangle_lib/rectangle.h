#include <string>

/**
 * 
 * This Class describes a Rectangle
 * 
 */
class Rectangle{
public:

	/**
	 * Creates a Rectangle Object with the given values for X, Y, Width and Height
	 */
	Rectangle(int x, int y, int width, int height);
	
	/**
	 * Creates an empty Rectangle Object
	 */
	Rectangle();

	/**
	 * Gives back the text version of this Rectangle's attributes
	 */
	std::string stringify() const;

	/**
	 * Checks the intersection between this and other, and returns the Rectangle of that intersection
	 */
	Rectangle intersection(const Rectangle& other) const;

	/**
	 * Returns the value of the variable m_empty
	 */
	bool isEmpty() const;
	
	/**
	 * getters
	 */
	int getX();
	int getY();
	int getW();
	int getH();
	
private:
	int m_x = 0;
	int m_y = 0;
	int m_w = 0;
	int m_h = 0;
	
	bool m_empty = false;

	/**
	 * empty Rectangle
	 */
	const static Rectangle emptyRectangle;
};

#include <string>

/**
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
	* Gives back the text version of this Rectangle's attributes
	*/
	std::string stringify();

private:
	int m_x = 0;
	int m_y = 0;
	int m_w = 0;
	int m_h = 0;
};

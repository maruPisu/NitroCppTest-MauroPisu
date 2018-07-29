#include <string>
#include <vector>

/// forward declaration of the struct defined in the bottom of this file
struct Intersection;

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
	Rectangle(int x, int y, int width, int height, std::string label);
	
	/**
	 * Creates an empty Rectangle Object
	 */
	Rectangle();

	/**
	 * Gives back the text version of this Rectangle's attributes
	 */
	std::string stringify() const;

	/**
	 * Returns the value of the variable m_empty
	 */
	bool isEmpty() const;
	
	/**
	 * Executes the intersection between all rectangles in input
	 */
	static std::vector<Intersection> intersect(const std::vector<Rectangle>& to_intersect);

	/**
	 * getters
	 */
	int getX() const;
	int getY() const;
	int getW() const;
	int getH() const;

	std::string getLabel() const;
	
private:
	/// coordinates
	int m_x = 0;
	int m_y = 0;
	/// size
	int m_w = 0;
	int m_h = 0;
	/// how to call this rectangle
	std::string m_label = 0;
	
	bool m_empty = false;

	/**
	 * empty Rectangle
	 */
	const static Rectangle emptyRectangle;

	/**
	 * Checks the intersection between this and other, and returns the Rectangle of that intersection
	 */
	Rectangle singleIntersection(const Rectangle& other) const;

	/**
	 * Recursively check deeper intersections between the pivot and the Rectangle vector to_intersect
	 */
	static std::vector<Intersection> higherLevelIntersections(const Intersection& pivot, const std::vector<Rectangle>& to_intersect);
};

/**
 * the return type of the function Intersect
 */
struct Intersection
{
	std::vector<std::string> rectanglesInvolved;
	Rectangle area;

	/**
	 * Gives back a formatted string containing the list of the rectangles involved
	 */
	std::string stringifyInvolved(){
		std::string result = "";
		for(int involved = 0; involved < rectanglesInvolved.size() ; ++involved){
			if(involved == rectanglesInvolved.size() - 2){
				result += rectanglesInvolved.at(involved) + " and ";
			}else if(involved == rectanglesInvolved.size() - 1){
				result += rectanglesInvolved.back();
			}else{
				result += rectanglesInvolved.at(involved) + ", ";
			}
		}
		return result;
	}
};

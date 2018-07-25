#include <sstream>
#include "rectangle.h"

const Rectangle Rectangle::emptyRectangle = Rectangle();

Rectangle::Rectangle(int x, int y, int width, int height)
	:m_x(x), m_y(y), m_w(width), m_h(height), m_empty(false)
{
	//a line (or a point) is not a rectangle
	if(m_h <= 0 or m_w <= 0){
		m_empty = true;
	}
}

Rectangle::Rectangle()
	:m_x(0), m_y(0), m_w(0), m_h(0), m_empty(true)
{}

std::string Rectangle::stringify() const{
	if(isEmpty()){
		return "";
		//return "empty rectangle\n";
	}
	std::ostringstream oss;
	oss
	   << "\t(" << m_x << "," << m_y << "), "
	   << "w=" << m_w << ", h=" << m_h
 	   << std::endl;

	return oss.str(); 
}

Rectangle Rectangle::intersection(const Rectangle& other) const{

	//if one or both rectangles are empty, return empty Rectangle
	if(this->isEmpty() or other.isEmpty()){
		return Rectangle::emptyRectangle;
	}

	//check if the 2 Rectangle intersect
	if( this->m_x + this->m_w <= other.m_x or other.m_x + other.m_w <= this->m_x or 
		this->m_y + this->m_h <= other.m_y or other.m_y + other.m_h <= this->m_y ){
		// No intersection
		return Rectangle::emptyRectangle;
	}

	//calculate the coordinates of the intersection
	int i_x = this->m_x > other.m_x ? this->m_x : other.m_x;
	int i_y = this->m_y > other.m_y ? this->m_y : other.m_y;

	int thisWBorder  = this->m_x + this->m_w;
	int otherWBorder = other.m_x + other.m_w;
	int thisHBorder  = this->m_y + this->m_h;
	int otherHBorder = other.m_y + other.m_h;

	int i_w = thisWBorder > otherWBorder ? otherWBorder - i_x : thisWBorder - i_x;
	int i_h = thisHBorder > otherHBorder ? otherHBorder - i_y : thisHBorder - i_y;

	//create the intersection Rectangle
	Rectangle ret(i_x, i_y, i_w, i_h);
	return ret;
}

bool Rectangle::isEmpty() const{
	return m_empty;
}

#include <sstream>
#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
	:m_x(x), m_y(y), m_w(width), m_h(height), m_empty(false)
{}
Rectangle::Rectangle()
	:m_x(0), m_y(0), m_w(0), m_h(0), m_empty(true)
{}

std::string Rectangle::stringify(){
	auto oss = std::ostringstream();

	oss
	   << "(" << m_x << "," << m_y << "), "
	   << "w=" << m_w << ", h=" << m_h
 	   << std::endl;

	return oss.str(); 
}

Rectangle Rectangle::intersection(const Rectangle& other){

}

bool Rectangle::isEmpty(){
	return m_empty;
}
#include <sstream>
#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
	:m_x(x), m_y(y), m_w(width), m_h(height)
{}

std::string Rectangle::stringify(){
	auto oss = std::ostringstream();

	oss
	   << "(" << m_x << "," << m_y << "), "
	   << "w=" << m_w << ", h=" << m_h
 	   << std::endl;

	return oss.str(); 
}
#include <iostream>
#include <sstream>
#include "rectangle.h"

using namespace std;

const Rectangle Rectangle::emptyRectangle;

Rectangle::Rectangle(int x, int y, int width, int height, std::string label)
	:m_x(x), m_y(y), m_w(width), m_h(height), m_label(label), m_empty(false)
{
	//a line (or a point) is not a rectangle
	if(m_h <= 0 or m_w <= 0){
		m_empty = true;
	}
}

Rectangle::Rectangle()
	:m_x(0), m_y(0), m_w(0), m_h(0), m_label(""), m_empty(true)
{}

std::string Rectangle::stringify() const{
	if(isEmpty()){
		return "";
		//return "empty rectangle\n";
	}
	std::ostringstream oss;
	oss
	   << "(" << m_x << "," << m_y << "), "
	   << "w=" << m_w << ", h=" << m_h
 	   << std::endl;

	return oss.str(); 
}

Rectangle Rectangle::singleIntersection(const Rectangle& other) const{

	//if one or both rectangles are empty, return empty Rectangle
	if(this->isEmpty() or other.isEmpty())
	{
		return Rectangle::emptyRectangle;
	}

	//check if the 2 Rectangle intersect
	if( this->m_x + this->m_w <= other.m_x or other.m_x + other.m_w <= this->m_x or 
		this->m_y + this->m_h <= other.m_y or other.m_y + other.m_h <= this->m_y )
	{
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
	Rectangle ret(i_x, i_y, i_w, i_h, "");
	return ret;
}

bool Rectangle::isEmpty() const{
	return m_empty;
}

std::vector<Intersection> Rectangle::intersect(const std::vector<Rectangle>& to_intersect){
	std::vector<Intersection> result;
	std::vector<Rectangle> intersectCopy = to_intersect;
	auto copyIter = intersectCopy.begin();

	for (auto iter = to_intersect.begin(); (iter != to_intersect.end()); iter++)
	{
		//build the next level to_intersect
		intersectCopy.erase(copyIter);

		//build a fake intersection
		Intersection thisIntersection;
		thisIntersection.rectanglesInvolved.push_back(iter->getLabel());
		thisIntersection.area = *iter;

		//call higherLevelIntersections
		auto toAppend = Rectangle::higherLevelIntersections(thisIntersection, intersectCopy);
		result.insert(result.end(), toAppend.begin(), toAppend.end());
	}
	return result;
}

std::vector<Intersection> Rectangle::higherLevelIntersections(const Intersection& pivot, const std::vector<Rectangle>& to_intersect){
	std::vector<Intersection> result;
	std::vector<Rectangle> intersectCopy = to_intersect;
	auto copyIter = intersectCopy.begin();

	for (auto iter = to_intersect.begin(); (iter != to_intersect.end()); iter++)
	{
		auto intersection = iter->singleIntersection(pivot.area);
		if(intersection.isEmpty())
		{
			// if there is no intersection, skip to the next rectangle
			++copyIter;
			continue;
		}
		
		//insert intersection in result
		Intersection thisIntersection;
		thisIntersection.rectanglesInvolved = pivot.rectanglesInvolved;
		thisIntersection.rectanglesInvolved.push_back(iter->getLabel());
		thisIntersection.area = intersection;
		result.push_back(thisIntersection);

		//build the next level to_intersect
		intersectCopy.erase(copyIter);

		//call higherLevelIntersections
		auto toAppend = Rectangle::higherLevelIntersections(thisIntersection, intersectCopy);
		result.insert(result.end(), toAppend.begin(), toAppend.end());
	}
	return result;
}

int Rectangle::getX() const{
	return m_x;
}

int Rectangle::getY() const{
	return m_y;
}

int Rectangle::getW() const{
	return m_w;
}

int Rectangle::getH() const{
	return m_h;
}

std::string Rectangle::getLabel() const{
	return m_label;
}

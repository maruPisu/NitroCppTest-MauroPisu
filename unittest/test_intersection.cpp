#include <rectangle.h>
#define BOOST_TEST_MODULE "TestIntersection"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( intersection )
{
	{	//intersection
		Rectangle rec1(1,1,4,4,"1");
		Rectangle rec2(0,0,2,2,"1");
		auto intersections = Rectangle::intersect({rec1, rec2});
		BOOST_CHECK(intersections.size() == 1);
		BOOST_CHECK(
			intersections.at(0).area.getX() == 1 &&
			intersections.at(0).area.getY() == 1 &&
			intersections.at(0).area.getW() == 1 &&
			intersections.at(0).area.getH() == 1
		);
	}
	
	{	//intersection
		Rectangle rec1(-1,-1,4,4,"1");
		Rectangle rec2(0,0,2,2,"1");
		auto intersections = rec1.intersect({rec1, rec2});
		BOOST_CHECK(intersections.size() == 1);
		BOOST_CHECK(
			intersections.at(0).area.getX() == 0 &&
			intersections.at(0).area.getY() == 0 &&
			intersections.at(0).area.getW() == 2 &&
			intersections.at(0).area.getH() == 2
		);
	}
	
	{	//no intersection
		Rectangle rec1(-1,-1,1,1,"1");
		Rectangle rec2(0,0,2,2,"1");
		auto intersections = rec1.intersect({rec1, rec2});
		BOOST_CHECK(intersections.size() == 0);
	}

	
	{	//multiple level
		Rectangle rec1(100,100,250,80,"1");
		Rectangle rec2(120,200,250,150,"1");
		Rectangle rec3(140,160,250,100,"1");
		Rectangle rec4(160,140,350,190,"1");
		auto intersections = rec1.intersect({rec1, rec2, rec3, rec4});
		BOOST_CHECK(intersections.size() == 7);
	}
	
}

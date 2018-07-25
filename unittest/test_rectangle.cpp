#include <rectangle.h>
#define BOOST_TEST_MODULE "TestRectangle"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( constructors )
{
	{	// empty rectangle
		Rectangle rec;
		BOOST_CHECK( rec.isEmpty());
	}
	
	{	// valid rectangle
		Rectangle rec(1,2,3,4);
		BOOST_CHECK( !rec.isEmpty());
	}
	
	{	//negative height
		Rectangle rec(1,2,3,-4);
		BOOST_CHECK( rec.isEmpty());
	}
	
	{	//null width
		Rectangle rec(1,2,0,4);
		BOOST_CHECK( rec.isEmpty());
	}
}

BOOST_AUTO_TEST_CASE( intersection )
{
	{	//intersection
		Rectangle rec1(1,1,4,4);
		Rectangle rec2(0,0,2,2);
		auto inter = rec1.intersection(rec2);
		BOOST_CHECK( !inter.isEmpty());
		BOOST_CHECK(
			inter.getX() == 1 &&
			inter.getY() == 1 &&
			inter.getW() == 1 &&
			inter.getH() == 1
		);
	}
	
	{	//intersection
		Rectangle rec1(-1,-1,4,4);
		Rectangle rec2(0,0,2,2);
		auto inter = rec1.intersection(rec2);
		BOOST_CHECK( !inter.isEmpty());
		BOOST_CHECK(
			inter.getX() == 0 &&
			inter.getY() == 0 &&
			inter.getW() == 2 &&
			inter.getH() == 2
		);
	}
	
	{	//no intersection
		Rectangle rec1(-1,-1,1,1);
		Rectangle rec2(0,0,2,2);
		auto inter = rec1.intersection(rec2);
		BOOST_CHECK( inter.isEmpty());
	}
	
}

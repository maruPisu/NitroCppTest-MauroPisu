#include <rectangle.h>
#define BOOST_TEST_MODULE "TestConstructor"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( constructors )
{
	{	// valid rectangle
		Rectangle rec(1,2,3,4,"1");
		BOOST_CHECK( !rec.isEmpty());
	}

	{	// empty rectangle
		Rectangle rec;
		BOOST_CHECK( rec.isEmpty());
	}
	
	{	//negative height
		Rectangle rec(1,2,3,-4,"1");
		BOOST_CHECK( rec.isEmpty());
	}
	
	{	//null width
		Rectangle rec(1,2,0,4,"1");
		BOOST_CHECK( rec.isEmpty());
	}
}


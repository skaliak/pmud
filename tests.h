#ifndef TESTS_CPP
#define TESTS_CPP

#include "region.h"
#include <cassert>

namespace pmudTests
{
	void TestIsInside()
	{
		int size = 10;
		Region r(size, true); //default region type.  Area should be size * size
		assert(r.getArea() == 100);

	}

	void RunAllTests()
	{
		TestIsInside();
	}



}
#endif // !TESTS_CPP
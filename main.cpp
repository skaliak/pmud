#include <cstdlib>
#include "gameController.h"
#include <time.h>
#include <cassert>

//#include <iostream>

using std::srand;

namespace pmudTests
{
	void TestIsInside()
	{
		int size = 10;
		Region r(size, true); //default region type.  Area should be size * size
		Point p1(5, 5);
		Point p2(20, 20);

		assert(r.isInside(p1));
		assert(! r.isInside(p2));
	}

	void RunAllTests()
	{
		//char c;
		TestIsInside();

		//std::cout << "tests successful!";
		//std::cin >> c;
	}



}

int main()
{
	//seed the rand  -- maybe the user should provide the seed?
	srand(time(NULL));

	pmudTests::RunAllTests();

	GameController gc;
	gc.Play();

	return 0;
}

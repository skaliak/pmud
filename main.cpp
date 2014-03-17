/*
Peter Lindberg
CS165 w2014
Final Project
*/
#include <cstdlib>
#include "gameController.h"
#include <time.h>
#include <cassert>
#include "factory.h"

#include <iostream>

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

	void TestGenerateWeaponName()
	{
		Factory f;
		string s = f.generateWeaponName();
		assert(s.length() > 0);
	}

	void GenerateSomeWeaponNames()
	{
		Factory f;
		for (int i = 0; i < 20; ++i)
		{
			std::cout << f.generateWeaponName() << "\n";
		}
	}

	void RunAllTests()
	{
		char c;
		TestIsInside();
		TestGenerateWeaponName();
		GenerateSomeWeaponNames();
		std::cout << "tests successful!";
		std::cin >> c;
	}



}

int main()
{
	//seed the rand  -- maybe the user should provide the seed?
	srand(time(NULL));

	//pmudTests::RunAllTests();
	try
	{
		GameController gc;
		gc.Play();
	}
	catch (int i)
	{
		if (i == 1)
		{
			std::cout << "ERROR: ran out of items while populating rooms -- increase MAX_ITEMS";
		}
		if (i == 2)
		{
			std::cout << "ERROR: ran out of critters while populating rooms -- increase MAX_CRITTERS";
		}
		else
			std::cout << "caught an unknown exception, probably during game setup";
	}

	

	return 0;
}

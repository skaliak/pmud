#include <cstdlib>
#include "gameController.h"
#include <time.h>

using std::srand;

int main()
{
	//seed the rand  -- maybe the user should provide the seed?
	srand(time(NULL));

	GameController gc;
	gc.Play();

	return 0;
}

#include <iostream>
#include "GameOfLife.h"

int main()
{
	bool** seed = new bool*[5];
	seed[0] = new bool[5]{ true, false, false, false, false };
	seed[1] = new bool[5]{ true, true, false, false, false };
	seed[2] = new bool[5]{ true, true, true, false, false };
	seed[3] = new bool[5]{ true, true, true, true, false };
	seed[4] = new bool[5]{ true, true, true, true, true };

	Life life(5, 5, seed);

	std::cout << life;

	system("PAUSE");
	return 0;
}
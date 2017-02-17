#include <iostream>
#include "Life.h"

int main()
{
	bool** seed = new bool*[5];
	seed[0] = new bool[5]{ true, false, false, false, false };
	seed[1] = new bool[5]{ true, true, false, false, false };
	seed[2] = new bool[5]{ true, true, true, false, false };
	seed[3] = new bool[5]{ true, true, true, true, false };
	seed[4] = new bool[5]{ true, true, true, true, true };

	Life life(5, 5, seed);

	std::cout << life << std::endl;


	bool** seed2 = new bool*[5];
	seed2[0] = new bool[5]{ true, false, false, false, true };
	seed2[1] = new bool[5]{ true, true, false, true, false };
	seed2[2] = new bool[5]{ true, true, false, false, false };
	seed2[3] = new bool[5]{ true, false, true, true, false };
	seed2[4] = new bool[5]{ false, true, true, true, true };
	
	life.reseed(5, 5, seed2);

	std::cout << life << std::endl;

	system("PAUSE");
	return 0;
}
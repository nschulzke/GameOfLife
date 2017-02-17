#include <iostream>
#include "Life.h"

int main()
{
	bool** seed = new bool*[5];
	seed[0] = new bool[5]{ false, false, false, false, false };
	seed[1] = new bool[5]{ false, false, false, false, false };
	seed[2] = new bool[5]{ false, true, true, true, false };
	seed[3] = new bool[5]{ false, false, false, false, false };
	seed[4] = new bool[5]{ false, false, false, false, false };

	Life life(5, 5, seed);

	std::cout << life << std::endl;
	life.step();
	std::cout << life << std::endl;
	life.step();
	std::cout << life << std::endl;
	life.step();
	std::cout << life << std::endl;
	life.step();
	std::cout << life << std::endl;


	system("PAUSE");
	return 0;
}
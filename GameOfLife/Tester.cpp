#include <iostream>
#include "Life.h"

int main()
{
	bool** seed = new bool*[10];
	seed[0] = new bool[10]{ false, false, true, false, false, false, false, false, false, false };
	seed[1] = new bool[10]{ true, false, true, false, false, false, false, false, false, false };
	seed[2] = new bool[10]{ false, true, true, false, false, false, false, false, false, false };
	seed[3] = new bool[10]{ false, false, false, false, false, false, false, false, false, false };
	seed[4] = new bool[10]{ false, false, false, false, false, false, false, false, false, false };
	seed[5] = new bool[10]{ false, false, false, false, false, false, false, false, false, false };
	seed[6] = new bool[10]{ false, false, false, false, false, false, false, false, false, false };
	seed[7] = new bool[10]{ false, false, false, false, false, false, false, false, false, false };
	seed[8] = new bool[10]{ false, false, false, false, false, false, false, false, false, false };
	seed[9] = new bool[10]{ false, false, false, false, false, false, false, false, false, false };

	Life life(10, 10, seed);

	for (int i = 0; i < 20; i++)
	{
		std::cout << life << std::endl;
		life.step();
	}

	system("PAUSE");
	return 0;
}
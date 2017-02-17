#include <iostream>
#include "Life.h"
#include "Seed.h"

int main()
{
	int rows = 20;
	int cols = 20;
	int rounds = 63;

	Seed seed = Seed::glider(rows, cols);

	Life life(seed);

	for (int i = 0; i < rounds; i++)
	{
		std::cout << life << std::endl;
		life.step();
	}

	life.overlay(seed);

	for (int i = 0; i < rounds; i++)
	{
		std::cout << life << std::endl;
		life.step();
	}

	system("PAUSE");
	return 0;
}
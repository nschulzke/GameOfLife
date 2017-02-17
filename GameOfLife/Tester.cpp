#include <iostream>
#include "Life.h"
#include "Seeder.h"

int main()
{
	int rows = 20;
	int cols = 20;
	int rounds = 63;

	bool** seed = Seeder::glider(rows, cols);

	Life life(rows, cols, seed);

	for (int i = 0; i < rounds; i++)
	{
		std::cout << life << std::endl;
		life.step();
	}

	life.overlay(rows, cols, seed);

	for (int i = 0; i < rounds; i++)
	{
		std::cout << life << std::endl;
		life.step();
	}

	Seeder::deleteSeed(rows, cols, seed);

	system("PAUSE");
	return 0;
}
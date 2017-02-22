#include <iostream>
#include <ctime>
#include "Life.h"
#include "Seed.h"

const int MICROS_PER_SECOND = 1000000;

int main()
{
	int rows = 20;
	int cols = 20;

	Seed seed = Seed::glider(rows, cols);

	Life life(seed);

	life.step(50);
	life.overlay(seed);

	while (life.hasLife())
	{
		std::cout << life << std::endl;
		life.step();
	}

	system("PAUSE");
	return 0;
}
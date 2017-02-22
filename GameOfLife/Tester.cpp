#include <iostream>
#include <ctime>
#include "Life.h"
#include "Seed.h"

const int MICROS_PER_SECOND = 1000000;

int main()
{
	Seed seed = Seed("test.txt");

	Life life(seed);

	for (int i = 0; i < 20; i++)
	{
		std::cout << life << std::endl;
		life.step();
	}

	system("PAUSE");
	return 0;
}
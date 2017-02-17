#include <iostream>
#include "Life.h"
#include "Seeder.h"

int main()
{
	bool** seed = Seeder::glider(10, 10);

	Life life(10, 10, seed);

	for (int i = 0; i < 20; i++)
	{
		std::cout << life << std::endl;
		life.step();
	}

	system("PAUSE");
	return 0;
}
#include <iostream>
#include <ctime>
#include "Life.h"
#include "Seed.h"

const int MICROS_PER_SECOND = 1000000;

int main()
{
	int rows = 200;
	int cols = 200;

	Seed seed = Seed::glider(rows, cols);

	Life life(seed);

	clock_t start;
	clock_t end;
	double ticks;
	double time;
	double average;

	start = clock();
	life.step(50);
	life.overlay(seed);

	while (life.hasLife())
		life.step();
	end = clock();
	ticks = end - start;
	time = (ticks / (double)CLOCKS_PER_SEC) * MICROS_PER_SECOND;
	average = time / life.steps();

	std::cout << "Steps to death: " << life.steps() << std::endl;
	std::cout << "Average time:   " << average << std::endl;

	system("PAUSE");
	return 0;
}
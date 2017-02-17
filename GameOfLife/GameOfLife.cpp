#include "GameOfLife.h"

Life::Life(int width, int height)
{
}

Life::~Life()
{
}

int Life::steps()
{
	return _steps;
}

void Life::step(int steps)
{
	for (int i = 0; i < steps; i++)
	{
		step();
	}
	_steps += steps;
}

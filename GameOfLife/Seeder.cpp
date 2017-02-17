#include "Seeder.h"

const bool Seeder::GLIDER[GLIDER_ROWS][GLIDER_COLS] = {
	{ false, true, false },
	{ false, false, true },
	{ true, true, true }
};

bool** Seeder::blankSeed(int rows, int cols)
{
	// Make the new seed
	bool** seed = new bool*[rows];
	// Create the rows
	for (int i = 0; i < rows; i++)
		seed[i] = new bool[cols];
	// Fill all cells with false
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			seed[i][j] = false;
	return seed;
}

bool** Seeder::glider(int rows, int cols)
{
	bool** seed = blankSeed(rows, cols);
	if (rows >= GLIDER_ROWS && cols >= GLIDER_COLS)
	{
		for (int i = 0; i < GLIDER_ROWS; i++)
			for (int j = 0; j < GLIDER_COLS; j++)
				seed[i][j] = GLIDER[i][j];
	}
	return seed;
}

void Seeder::deleteSeed(int rows, int cols, bool ** seed)
{
	// If there's no board, we can't run this loop, so do nothing
	if (seed != nullptr)
	{	// Loop through all rows and delete them
		for (int i = 0; i < rows; i++)
			delete[] seed[i];
		// Delete the row array
		delete[] seed;
	}
}

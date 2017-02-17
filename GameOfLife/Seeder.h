#pragma once

class Seeder
{
private:
	static const int GLIDER_ROWS = 3;
	static const int GLIDER_COLS = 3;
	static const bool GLIDER[GLIDER_ROWS][GLIDER_COLS];

	static bool** blankSeed(int rows, int cols);
public:
	static bool** glider(int rows, int cols);

	static void deleteSeed(int rows, int cols, bool** seed);
};


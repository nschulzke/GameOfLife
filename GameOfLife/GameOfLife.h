#pragma once

#include <iostream>
#include "Cell.h"

class Life
{
private:
	Cell** _board;
	int _steps;
	
	// Will return true if the given cell will be alive
	//	after a step
	bool isAlive(int row, int col);
	// Goes through the board once and mark all cells
	//	as to whether they'll be alive or dead next round
	void mark();
	// Goes through a marked board and actually switch the
	//	marked cells to be dead or alive
	void move();
public:
	// Expects the passed seed array to be of the same width
	//	and height as the values passed
	Life(int width, int height, int** seed);
	~Life();

	// Returns the number of steps that have been taken on
	//	the current seed
	int steps();
	// Steps through the given number of iterations
	void step(int steps = 1);

	// Reseeds the array with a new seed of given width and height
	void reseed(int width, int height, int** seed);
};

// Outputs the current game in a grid format. Particularly large grids
//	may not render correctly.
std::ostream& operator<< (std::ostream& out, const Life& s);
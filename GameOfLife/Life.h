#pragma once

#include <iostream>
#include "Cell.h"

class Life
{
private:
	Cell** _board;
	int _rows;
	int _cols;
	int _steps;
	// Deletes the board. Used by destructor and reseed();
	void deleteBoard();
	// Marks the given cell as to whether it will be alive
	//	or dead in the next round by examining surrounding cells
	void mark(int row, int col);
	// Goes through the board once and mark all cells
	void mark();
	// Goes through a marked board and actually switch the
	//	marked cells to be dead or alive
	void move();
public:
	// Expects the passed seed array to be of the same width
	//	and height as the values passed
	Life(int rows, int cols, bool** seed);
	~Life();

	// Returns the number of steps that have been taken on
	//	the current seed
	int steps() const;
	// Getters for _rows and _cols
	int rows() const;
	int cols() const;
	// Returns the alive state of the given cell
	bool isAlive(int row, int col) const;

	// Steps through the given number of iterations
	void step(int steps = 1);

	// Reseeds the array with a new seed of given width and height
	void reseed(int rows, int cols, bool** seed);
};

// Outputs the current game in a grid format. Particularly large grids
//	may not render correctly.
std::ostream& operator<< (std::ostream& out, const Life& s);
#pragma once

#include <iostream>
#include "Cell.h"

class Life
{
private:
	// Cells with FEWER neighbors than this will die
	const static int STARVE = 2;
	// Cells with MORE neighbors than this will die
	const static int OVERPOP = 3;
	// Cells with EXACTLY this many neighbors will become living if they were dead
	const static int REPRODUCE = 3;

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
	// Takes the current board and overlays a new seed
	//	Any cells living in the new seed will be living on the board
	//	Dead cells on new seed have no effect on the board
	void overlay(int rows, int cols, bool** seed);
};

// Outputs the current game in a grid format. Particularly large grids
//	may not render correctly.
std::ostream& operator<< (std::ostream& out, const Life& s);
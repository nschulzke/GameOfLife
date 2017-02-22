#pragma once

#include <iostream>
#include "Cell.h"
#include "Seed.h"

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

	// Marks the given cell as to whether it will be alive
	//	or dead in the next round by examining surrounding cells
	void mark(int row, int col);

	// Deletes the board
	void deleteBoard();
	// Allocates memory for board
	void blankBoard(int rows, int cols);
	// Copies _rows, _cols, _steps, and dynamic _board from lifeIn
	void deepCopy(const Life& lifeIn);
public:
	// Construct from a seed
	Life(const Seed& seed);
	// Copy constructor
	Life(const Life& lifeIn);
	// Assignment operator
	Life& operator=(const Life& rhs);
	// Destructor
	~Life();

	// Returns the number of steps that have been taken on
	//	the current seed
	int steps() const;
	// Getters for _rows and _cols
	int rows() const;
	int cols() const;
	// Returns the alive state of the given cell
	bool isAlive(int row, int col) const;
	// Returns whether or not any cells are still living
	bool hasLife() const;

	// Steps through the given number of iterations
	void step(int steps = 1);

	// Reseeds the array with a new seed
	void reseed(const Seed& seed);
	// Takes the current board and overlays a new seed
	//	Any cells living in the new seed will be living on the board
	//	Dead cells on new seed have no effect on the board
	void overlay(const Seed& seed);
};

// Outputs the current game in a grid format. Particularly large grids
//	may not render correctly.
std::ostream& operator<< (std::ostream& out, const Life& s);
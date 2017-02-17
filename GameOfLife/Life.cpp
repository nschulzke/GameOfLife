#include "Life.h"

void Life::deleteBoard()
{
	// If there's no board, we can't run this loop, so do nothing
	if (_board != nullptr)
	{	// Loop through all rows and delete them
		for (int i = 0; i < _rows; i++)
			delete[] _board[i];
		// Delete the row array
		delete[] _board;
	}
}

void Life::mark(int row, int col)
{
	// These values draw a box around the cell, cells making up the box
	// are the cells we need to check
	int minRow = (row == 0) ? 0 : row - 1;
	int maxRow = (row == (_rows - 1)) ? _rows - 1 : row + 1;
	int minCol = (col == 0) ? 0 : col - 1;
	int maxCol = (col == (_cols - 1)) ? _cols - 1 : col + 1;

	int livingNeighbors = 0;
	for (int i = minRow; i <= maxRow; i++)
	{
		for (int j = minCol; j <= maxCol; j++)
		{
			// Only check the cells that aren't the middle
			if (i != row || j != col)
				if (_board[i][j].isAlive())
					livingNeighbors++;
		}
	}

	if (livingNeighbors < STARVE || livingNeighbors > OVERPOP)
		_board[row][col].willBeAlive(false);
	else if (livingNeighbors == REPRODUCE)
		_board[row][col].willBeAlive(true);
	// If it's not either of these, willBeAlive is already the same as isAlive, so we do nothing
}

void Life::mark()
{
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			mark(i, j);
}

void Life::move()
{
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			_board[i][j].step();
}

Life::Life(int rows, int cols, bool** seed)
{	// Set the board to nullptr, then reseed
	_board = nullptr;
	reseed(rows, cols, seed);
}

Life::~Life()
{	// Just delete the board, we have no other dynamic memory
	deleteBoard();
}

int Life::steps() const
{
	return _steps;
}

int Life::rows() const
{
	return _rows;
}

int Life::cols() const
{
	return _cols;
}

bool Life::isAlive(int row, int col) const
{	// Return the alive status of the specified cell
	return _board[row][col].isAlive();
}

void Life::step(int steps)
{
	for (int i = 0; i < steps; i++)
	{
		mark();
		move();
	}
	_steps += steps;
}

void Life::reseed(int rows, int cols, bool** seed)
{
	// If there's already a board, make sure we delete it
	deleteBoard();
	// Set the rows and cols properties
	_rows = rows;
	_cols = cols;
	// Create the new board
	_board = new Cell*[rows];
	for (int i = 0; i < rows; i++)
		_board[i] = new Cell[cols];
	// Initialize the values to match the seed
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			_board[i][j] = Cell(seed[i][j]);
	// Reset _steps to 0 so we can count again
	_steps = 0;
}

std::ostream & operator<<(std::ostream & out, const Life& life)
{
	for (int i = 0; i < life.rows(); i++)
	{
		for (int j = 0; j < life.cols(); j++)
			out << (life.isAlive(i, j) ? (char)233 : '-') << ' ';
		out << std::endl;
	}
	return out;
}

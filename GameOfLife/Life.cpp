#include "Life.h"

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

void Life::deleteBoard()
{
	// If there's no board, we can't run this loop, so do nothing
	if (_board != nullptr)
	{	// Loop through all rows and delete them
		for (int i = 0; i < _rows; i++)
			delete[] _board[i];
		// Delete the row array
		delete[] _board;
		_board = nullptr;
	}
}

void Life::blankBoard(int rows, int cols)
{
	_board = new Cell*[_rows];
	for (int i = 0; i < _rows; i++)
		_board[i] = new Cell[_cols];
}

void Life::deepCopy(const Life& lifeIn)
{	// Make every value in this = every value in lifeIn
	_rows = lifeIn._rows;
	_cols = lifeIn._cols;
	_steps = lifeIn._steps;
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _rows; j++)
			_board[i][j] = lifeIn._board[i][j];
}

Life::Life(const Seed& seed)
{
	_board = nullptr;
	reseed(seed);
}

Life::Life(const Life& lifeIn)
{
	blankBoard(lifeIn.rows(), lifeIn.cols());
	deepCopy(lifeIn);
}

Life& Life::operator=(const Life& rhs)
{	// Shortcut: don't copy if this=this
	if (this == &rhs)
		return *this;
	// Delete the current seed and deep copy from the other guy
	deleteBoard();
	blankBoard(rhs.rows(), rhs.cols());
	deepCopy(rhs);

	return *this;
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

bool Life::hasLife() const
{
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			if (_board[i][j].isAlive())
				return true;
	return false;
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

void Life::reseed(const Seed& seed)
{
	// If there's already a board, make sure we delete it
	deleteBoard();
	// Set the rows and cols properties
	_rows = seed.rows();
	_cols = seed.cols();
	// Create the new board
	blankBoard(_rows, _cols);
	// Initialize the values to match the seed
	for (int i = 0; i < seed.rows(); i++)
		for (int j = 0; j < seed.cols(); j++)
			_board[i][j] = Cell(seed.isAlive(i,j));
	// Reset _steps to 0 so we can count again
	_steps = 0;
}

void Life::overlay(const Seed& seed)
{
	for (int i = 0; i < seed.rows(); i++)
		for (int j = 0; j < seed.cols(); j++)
			if (seed.isAlive(i,j) == true)	// Only change board if the cell is alive
				_board[i][j] = Cell(seed.isAlive(i,j));
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

#include "Seed.h"

const bool Seed::GLIDER[GLIDER_ROWS][GLIDER_COLS] = {
	{ false, true, false },
	{ false, false, true },
	{ true, true, true }
};

void Seed::blankSeed(int rows, int cols)
{
	// Make the new seed
	_seed = new bool*[rows];
	// Create the rows
	for (int i = 0; i < rows; i++)
		_seed[i] = new bool[cols];
	// Fill all cells with false
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < _cols; j++)
			_seed[i][j] = false;
}

void Seed::deepCopy(const Seed& seedIn)
{	// Make every value in this = every value in seedIn
	_rows = seedIn._rows;
	_cols = seedIn._cols;
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			_seed[i][j] = seedIn._seed[i][j];
}

void Seed::deleteSeed()
{
	// If there's no board, we can't run this loop, so do nothing
	if (_seed != nullptr)
	{	// Loop through all rows and delete them
		for (int i = 0; i < _rows; i++)
			delete[] _seed[i];
		// Delete the row array
		delete[] _seed;
	}
}

Seed::Seed(int rows, int cols)
{
	_rows = rows;
	_cols = cols;
	blankSeed(_rows, _cols);
}

Seed::Seed(const Seed& seedIn)
{	// Copy constructor: first build a blank Seed, then copy the data from seedIn
	blankSeed(seedIn.rows(), seedIn.cols());
	deepCopy(seedIn);
}

Seed& Seed::operator=(const Seed & rhs)
{	// Shortcut: don't copy if this=this
	if (this == &rhs)
		return *this;
	// Delete the current seed and deep copy from the other guy
	deleteSeed();
	blankSeed(_rows, _cols);
	deepCopy(rhs);

	return *this;
}

Seed::~Seed()
{
	deleteSeed();
}

Seed Seed::glider(int rows, int cols)
{	// Factory method to produce a glider seed
	Seed seed(rows, cols);	// Blank seed
	if (rows >= GLIDER_ROWS && cols >= GLIDER_COLS)
	{	// Impose the glider template (defined above) onto the blank seed
		for (int i = 0; i < GLIDER_ROWS; i++)
			for (int j = 0; j < GLIDER_COLS; j++)
				seed._seed[i][j] = GLIDER[i][j];
	}
	return seed;
}

int Seed::rows() const
{
	return _rows;
}

int Seed::cols() const
{
	return _cols;
}

bool Seed::isAlive(int row, int col) const
{
	return _seed[row][col];
}

void Seed::isAlive(int row, int col, bool trueFalse)
{
	_seed[row][col] = trueFalse;
}

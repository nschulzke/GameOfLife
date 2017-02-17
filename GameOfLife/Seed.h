#pragma once

class Seed
{
private:
	// Info for the glider template
	static const int GLIDER_ROWS = 3;
	static const int GLIDER_COLS = 3;
	static const bool GLIDER[GLIDER_ROWS][GLIDER_COLS];

	// Generates the dynamic memory array, initializes all data to false
	static bool** blankSeed(int rows, int cols);

	int _rows;
	int _cols;
	bool** _seed;

	// Copies _rows, _cols, and dynamic _seed from seedIn
	void deepCopy(const Seed& seedIn);
	// Deletes _seed
	void deleteSeed();
public:
	// Make a Seed object from a bool**
	Seed(int rows, int cols, bool** seed);
	// Copy constructor
	Seed(const Seed& seedIn);
	// Assignment operator
	Seed& operator=(const Seed& rhs);
	// Destructor
	~Seed();
	// Factory method that produces a Seed with a glider
	static Seed glider(int rows, int cols);

	// Getters for _rows and _cols
	int rows() const;
	int cols() const;
	// Gets alive status of given cell
	bool isAlive(int row, int col) const;

	// Sets the cell at given row/col to alive or dead
	void isAlive(int row, int col, bool trueFalse);
};


#pragma once

#include <fstream>
#include <string>
#include <vector>

class Seed
{
private:
	// Info for the glider template
	static const int GLIDER_ROWS = 3;
	static const int GLIDER_COLS = 3;
	static const bool GLIDER[GLIDER_ROWS][GLIDER_COLS];

	int _rows;
	int _cols;
	bool** _seed;

	// Generates the dynamic memory array, initializes all data to false
	void blankSeed(int rows, int cols);
	// Copies _rows, _cols, and dynamic _seed from seedIn
	void deepCopy(const Seed& seedIn);
	// Deletes _seed
	void deleteSeed();
public:
	// Make a Seed object from a bool**
	Seed(int rows, int cols);
	// Load a Seed from a file
	Seed(std::string fileName);
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

	void loadFile(std::string fileName);

	// Sets the cell at given row/col to alive or dead
	void isAlive(int row, int col, bool trueFalse);
};


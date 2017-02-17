#pragma once
class Cell
{
private:
	bool _isAlive;
	bool _willBeAlive;
public:
	// Returns whether the cell is currently alive
	bool isAlive();
	// Returns whether the cell will be alive after a step
	bool willBeAlive();
	// Sets the future state of the cell to alive or dead
	void willBeAlive(bool trueFalse);
	// Makes the future state the current state
	void step();

	Cell(bool isAlive);
};


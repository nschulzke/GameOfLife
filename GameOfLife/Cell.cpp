#include "Cell.h"

bool Cell::isAlive() const
{
	return _isAlive;
}

bool Cell::willBeAlive() const
{
	return _willBeAlive;
}

void Cell::willBeAlive(bool trueFalse)
{
	_willBeAlive = trueFalse;
}

void Cell::step()
{
	_isAlive = _willBeAlive;
}

Cell::Cell(bool isAlive)
{
	_isAlive = isAlive;
	_willBeAlive = isAlive;
}

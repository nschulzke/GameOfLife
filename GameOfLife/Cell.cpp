#include "Cell.h"

bool Cell::isAlive()
{
	return _isAlive;
}

bool Cell::willBeAlive()
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

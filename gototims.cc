#include "gototims.h"

// changes the player's position to the Tim's Line
GoToTims::action()
{
	occupying->position = theBoard.squareArr[10];
}

// destructor
GoToTims::~GoToTims()
{
	delete occupying;
}
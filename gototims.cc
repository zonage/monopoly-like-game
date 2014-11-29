#include "gototims.h"

// changes the player's position to the Tim's Line
GoToTims::action()
{
	cout "You've been sent to the DC Tim's Line!" << endl;
	occupying->position = theBoard.squareArr[10];
	occupying->position->action();
}

// destructor
GoToTims::~GoToTims()
{
	delete occupying;
}
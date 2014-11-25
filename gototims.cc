#include "gototims.h"

GoToTims::action()
{
	occupying->position = theBoard.squareArr[10];
}

GoToTims::~GoToTims()
{
	delete occupying;
}
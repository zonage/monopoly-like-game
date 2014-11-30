#include "timsline.h"

// action: makes players stay on spot until rolling doubles or use tim cup
void TimsLine::action()
{
	if(occupying->TimTurns == 0) 
	{
		cout << "You've lined up in the DC Tim's Line." << endl;
	}
	else
	{
		cout << "Nothing to Line up for." << endl;
	}
}

// destructor
TimsLine::~TimsLine()
{
	delete occupying;
}
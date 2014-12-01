#include <iostream>
#include "gototims.h"
#include "theboard.h"

using namespace std;
//TheBoard *TB;

// changes the player's position to the Tim's Line
void GoToTims::action()
{
	cout << "You've been sent to the DC Tim's Line!" << endl;
	occupying->position = TB->squareArr[10];
	occupying->position->action();
}

// destructor
GoToTims::~GoToTims()
{
	delete occupying;
}

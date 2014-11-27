#include "slc.h"

// action: gives the player a tims card or moves the player to random place on the board
SLC::action() 
{
	// pointer to the TimsLine square
	TimsLine * timmies = theBoard.squareArr[10];
	int todo = rand() % 100 + 1;

	// checks whether to give out timCard or normal behaviour
	if ((todo == 57) && (timmies->cardsinplay < 5))
	{

		// gives player a timCard and increments the number of cards in play
		occupying->timCards++;
		timmies->cardsinplay++;
	}
	else
	{
		//
		int randnum = rand() % 24 + 1;
		if (randnum < 4)
		{
			occupying->loc -= 3;
			occupying->position =  theBoard.squareArr[loc];
		}
		else if (randnum < 8)
		{
			occupying->loc -= 2;
			occupying->position =  theBoard.squareArr[loc];
		}
		else if (randnum < 12)
		{
			occupying->loc -= 1;
			occupying->position =  theBoard.squareArr[loc];
		}
		else if (randnum < 15)
		{
			occupying->loc += 1;
			occupying->position =  theBoard.squareArr[loc];
		}
		else if (randnum < 19)
		{
			occupying->loc += 2;
			occupying->position =  theBoard.squareArr[loc];
		}
		else if (randnum < 23)
		{
			occupying->loc += 3;
			occupying->position =  theBoard.squareArr[loc];
		}
		else if (randnum == 23)
		{
			occupying->loc = 10;
			occupying->position =  theBoard.squareArr[loc];
		}
		else if (randnum == 24)
		{
			occupying->loc = 0;
			occupying->position =  theBoard.squareArr[loc];
		}
	}

}

// destructor
SLC::~SLC()
{
	delete occupying;
}
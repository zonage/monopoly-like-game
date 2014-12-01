#include "slc.h"
#include <cstdlib>
#include <ctime>
#include "timsline.h"
#include "theboard.h"
#include "square.h"
using namespace std;

//TheBoard *TB;

// action: gives the player a tims card or moves the player to random place on the board
void SLC::action() 
{	
	srand(time(NULL));
	// pointer to the TimsLine square
	Square *TLs = TB->squareArr[10];
	TimsLine * timmies = dynamic_cast<TimsLine *>(TLs);
	int todo = rand() % 100 + 1;

	// checks whether to give out timCard or normal behaviour
	if ((todo == 57) && (timmies->cupsinplay < 5))
	{

		// gives player a timCard and increments the number of cards in play
		occupying->RimCups++;
		timmies->cupsinplay++;
	}
	else
	{
		//
		int randnum = rand() % 24 + 1;
		if (randnum < 4)
		{
			occupying->loc -= 3;
			occupying->position = TB->squareArr[occupying->loc];
		}
		else if (randnum < 8)
		{
			occupying->loc -= 2;
			occupying->position = TB->squareArr[occupying->loc];
		}
		else if (randnum < 12)
		{
			occupying->loc -= 1;
			occupying->position = TB->squareArr[occupying->loc];
		}
		else if (randnum < 15)
		{
			occupying->loc += 1;
			occupying->position = TB->squareArr[occupying->loc];
		}
		else if (randnum < 19)
		{
			occupying->loc += 2;
			occupying->position =  TB->squareArr[occupying->loc];
		}
		else if (randnum < 23)
		{
			occupying->loc += 3;
			occupying->position =  TB->squareArr[occupying->loc];
		}
		else if (randnum == 23)
		{
			occupying->loc = 10;
			occupying->position = TB->squareArr[occupying->loc];
		}
		else if (randnum == 24)
		{
			occupying->loc = 0;
			occupying->position = TB->squareArr[occupying->loc];
		}
	}

}

// destructor
SLC::~SLC()
{
	delete occupying;
}

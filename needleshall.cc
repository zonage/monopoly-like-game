#include <cstdlib>
#include <ctime>
#include "needleshall.h"
#include "timsline.h"
#include "theboard.h"
#include "square.h"

using namespace std;
//TheBoard *TB;

// action: gives the player a tims card or 
void NeedlesHall::action()
{
	srand(time(NULL));
	// pointer to the TimsLine square
	Square *TLs = TB->squareArr[10];
        TimsLine *timmies = dynamic_cast<TimsLine*>(TLs);

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
		int randnum = rand() % 18 + 1;
		if (randnum == 1)
		{
			occupying->money += 200;
		}
		else if (randnum < 4)
		{
			occupying->money += 100;
		}
		else if (randnum < 7)
		{
			occupying->money += 50;
		}
		else if (randnum < 13)
		{
			occupying->money += 25;
		}
		else if (randnum < 16)
		{
			occupying->money -= 50;
		}
		else if (randnum < 18)
		{
			occupying->money -= 100;
		}
		else if (randnum == 18)
		{
			occupying->money -= 200;
		}
	}
}

NeedlesHall::~NeedlesHall()
{
	delete occupying;
}

#include "needleshall.h"

// action: gives the player a tims card or 
NeedlesHall::action()
{
	TimsLine * timmies = theBoard.squareArr[10];
	int todo = rand() % 100 + 1;
	if ((todo == 57) && (timmies->cardsinplay < 5))
	{
		occupying->timCards++;
		timmies->cardsinplay++;
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
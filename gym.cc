#include <iostream>
#include <cstdlib>
#include <ctime>
#include "gym.h"

using namespace std;

Gym::Gym(string title, int cost, string mBlockName, int rent, int number, 
	bool purchased, bool mortgaged, Player *owner, Player *occupying):
	Property(title, cost, mBlockName, rent, number, purchased, mortgaged, owner, occupying) {}

Gym::~Gym() {}

void Gym::action() {
	srand(time(NULL));
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
        int count;
	
	for (int i=0; i<6; ++i) {
 	  if((mBlockName == owner->monopolies[i]->blockName)) {
 	    count = owner->monopolies[i]->numP;
 	    break;
 	  } else {
            count =1;
       	  }
 	}

	int amount;

	if (count == 1) {
		amount = (die1+die2)*4;
	} else if (count == 2) {
		amount = (die1+die2)*10;
	}
	occupying->addMoney(-amount);
}

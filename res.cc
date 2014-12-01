#include "res.h"
using namespace std;

Res::Res(string title, int cost, string mBlockName, int rent, int number, 
	bool purchased, bool mortgaged, Player *owner, Player *occupying):
	Property(title, cost, mBlockName, rent, number, purchased, mortgaged, owner, occupying) {}

Res::~Res() {}

void Res::action() {
	int count;
	for (int i=0; i<6; ++i) {
 		if(mBlockName == owner->monopolies[i]->blockName) {
 		  count = owner->monopolies[i]->numP;
 		  break;
 		} else {
 		  count =0;
 		}
 	}
	int amount = rent * count;
	occupying->addMoney(-amount);
}

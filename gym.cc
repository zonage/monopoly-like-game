#include gym.h

using namespace std;

Gym::Gym(string title, int cost, string mBlockName, int rent, 
	bool purchased, bool mortgaged, Player *owner, Player *occupying):
	Property(number, title, cost, mBlockName, rent, purchased, mortgaged, owner, occupying) {}

Gym::~Gym() {}

void Gym::action() {
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	
	int count = owner->assets[mBlockName]->numP;
	int amount;

	if (count == 1) {
		amount = (die1+die2)*4;
	} else if (count == 2) {
		amount = (die1+die2)*10;
	}
	w
	occupying->addMoney(-amount);
}

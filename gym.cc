#include gym.h

using namespace std;

Gym::Gym(string title, int cost, bool purchased=0, bool mortgaged=0,
 		Player *owner=NULL, Player *occupying=NULL, string mBlockName):
		title(title), cost(cost), mBlockName(mBlockName) {}

Gym::~Gym() {}

Gym::action() {
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
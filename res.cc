#include "res.h"

Res::Res(string title, int cost, bool purchased=0, bool mortgaged=0,
 		Player *owner=NULL, Player *occupying=NULL, string mBlockName, int rent):
		title(title), cost(cost), mBlockName(mBlockName), rent(rent) {}

Res::~Res() {}

Res::action() {
	int count = owner->assets[mBlockName]->numP;
	int amount = rent * numP;
	occupying->addMoney(-amount);
}

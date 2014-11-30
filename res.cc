#include "res.h"
using namespace std;

Res::Res(string title, int cost, string mBlockName, int rent, 
	bool purchased, bool mortgaged, Player *owner, Player *occupying):
	Property(number, title, cost, mBlockName, rent, purchased, mortgaged, owner, occupying) {}

Res::~Res() {}

void Res::action() {
	int count = owner->assets[mBlockName]->numP;
	int amount = rent * numP;
	occupying->addMoney(-amount);
}

#include "property.h"
using namespace std;

// constructor
Property::Property(int number, string title, int cost, string mBlockName, int rent,
			bool purchased, bool mortgaged, Player *owner, Player *occupying):
			Square(number, title, cost, mBlockName, rent, purchased, mortgaged,
			owner, occupying) {}

// destructor
Property::~Property() {}

void Property::buy() {
	owner = occupying;
	owner->addMoney(-cost);
	purchased = true;
}

void Property::mortgage() {
	mortgaged = true;
	owner->addMoney(cost/2);
}

#include "property.h"
using namespace std;

// constructor
Property::Property(bool purchased, bool mortgaged, Player *owner):
		purchased(purchased), mortgaged(mortgaged), owner(owner) {}

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

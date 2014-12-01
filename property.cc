#include "property.h"
using namespace std;

// constructor
Property::Property(string title, int cost, string mBlockName, int rent, int number, 
			bool purchased, bool mortgaged, Player *owner, Player *occupying):
			Square(title, cost, mBlockName, rent, number, purchased, mortgaged,
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

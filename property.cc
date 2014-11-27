#include "property.h"
using namespace std;

// constructor
Property::Property(string title, int cost, bool purchased=0, bool mortgaged=0, Player *owner=NULL): 
	title(title), cost(cost) {}

// destructor
Property::~Property() {}

Property::buy() {
	owner = occupying;
	owner->addMoney(-cost);
	purchased = true;
}

Property::mortgage() {
	mortgaged = true;
	owner->addMoney(cost/2);
}
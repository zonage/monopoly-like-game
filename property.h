#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include "square.h"
#include <string>

class Property: public Square {
public:
	string title;
	int cost;
	bool purchased;
	bool mortgaged;
	Player *owner;
	Player *occupying;

	Property(string title, int cost, bool purchased, bool mortgaged, Player *owner);
	virtual ~Property() = 0;
	void buy();
	virtual void action() = 0;
	void mortgage();
};

#endif
#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include <string>

class Property {
public:
	string title;
	int cost;
	bool purchased;
	bool mortgaged;
	Player *owner;
	Player *occupying;

	void Property(string title, int cost, bool purchased, bool mortgaged, Player *owner);
	virtual ~Property() = 0;
	void buy();
	void virtual collectRent() = 0;
	void mortgage();
};

#endif
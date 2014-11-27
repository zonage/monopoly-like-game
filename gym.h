#ifndef __GYM_H__
#define __GYM_H__
#include "property.h"
#include <string>

class Gym: public Property {
public:
	string mBlockName;
	int rent;

	Gym(string title, int cost, bool purchased, bool mortgaged,
 		Player *owner, Player *occupying, string mBlockName);
	~Gym();
	virtual void action();
};

#endif
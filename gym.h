#ifndef __GYM_H__
#define __GYM_H__
#include <string>

class Gym {
public:
	string mBlockName;
	int rent;

	Gym(string title, int cost, bool purchased, bool mortgaged,
 		Player *owner, Player *occupying, string mBlockName, int rent);
	~Gym();
};

#endif
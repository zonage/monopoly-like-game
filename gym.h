#ifndef __GYM_H__
#define __GYM_H__
#include "property.h"
#include <string>

class Gym: public Property {
public:
/*	std::string title;
	int cost;
	std::string mBlockName;
	int rent;*/

	Gym(std::string title="", int cost=0, std::string mBlockName="", int rent=0, int number=0, 
		bool purchased=0, bool mortgaged=0, Player *owner=NULL, Player *occupying=NULL);

	~Gym();
	virtual void action();
};

#endif

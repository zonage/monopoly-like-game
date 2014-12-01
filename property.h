#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include "square.h"
#include "player.h"
#include <string>

class Property: public Square {
	public:
	
/*	bool purchased;
	bool mortgaged;
	Player *owner;
	Player *occupying;*/

	Property(std::string title="", int cost=0, std::string mBlockName="", int rent=0, int number=0, 
			bool purchased=0, bool mortgaged=0, Player *owner=NULL, Player *occupying=NULL);
	virtual ~Property();
	void buy();
	virtual void action() = 0;
	void mortgage();
};

#endif

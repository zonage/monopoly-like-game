#ifndef __RES_H__
#define __RES_H__
#include "property.h"
#include <string>

class Res: public Property {
public:
	string mBlockName;
	int rent;

	Res(string title, int cost, bool purchased, bool mortgaged,
 		Player *owner, Player *occupying, string mBlockName, int rent);
	~Res();
	virtual void action();
};

#endif
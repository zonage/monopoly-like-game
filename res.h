#ifndef __RES_H__
#define __RES_H__
#include "property.h"
#include <string>

class Res: public Property {
public:
/*	std::string title;
	int cost;
	std::string mBlockName;
	int rent;*/

	Res(std::string title="", int cost=0, std::string mBlockName="", int rent=0, int number=0, 
			bool purchased=0, bool mortgaged=0, Player *owner=NULL, Player *occupying=NULL);

	~Res();
	virtual void action();
};

#endif

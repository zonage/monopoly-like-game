#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include "property.h"
#include <string>

class AcademicBuilding: public Property{
public:
	string mBlockName;
	int rent;
	int improvements;
	int imprvCost;

	AcademicBuilding(string title, int cost, bool purchased, bool mortgaged,
 		Player *owner, Player *occupying, int rent, int improvements, int imprvCost);
	~AcademicBuilding();
	void improve();
	virtual void action();
};

#endif

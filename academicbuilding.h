#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include "property.h"
#include <string>

class AcademicBuilding: public Property{
public:
/*	std::string title;
	int cost;
	std::string mBlockName;
	int rent;*/
	int improvements;
	int imprvCost;

AcademicBuilding(std::string title="", int cost=0, std::string mBlockName="", int rent=0, int imprvCost=0,
				int number=0, bool purchased=0, bool mortgaged=0, 
				Player *owner=NULL, Player *occupying=NULL, int improvements=0);

	~AcademicBuilding();
	void improve();
	virtual void action();
};

#endif

#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include "property.h"
#include <string>

class AcademicBuilding: public Property{
public:
	std::string mBlockName;
	int rent;
	int improvements;
	int imprvCost;

AcademicBuilding(std::string title, int cost, std::string mBlockName, int rent,
		int imprvCost, bool purchased=false, bool mortgaged=false, 
		int improvements=0, Player *owner=NULL, Player *occupying=NULL);

	~AcademicBuilding();
	void improve();
	virtual void action();
};

#endif

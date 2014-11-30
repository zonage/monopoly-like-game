#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include "property.h"
#include <string>

class AcademicBuilding: public Property{
public:
	std::string title;
	int cost;
	std::string mBlockName;
	int rent;
	int improvements;
	int imprvCost;

AcademicBuilding(std::string title, int cost, std::string mBlockName, int rent, int imprvCost, int improvements=0);

	~AcademicBuilding();
	void improve();
	virtual void action();
};

#endif

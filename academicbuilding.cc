#include "academicbuilding.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include <math.h> 
#include <iostream>

using namespace std;

AcademicBuilding::AcademicBuilding(int number, string title, int cost, string mBlockName, int rent,
						bool purchased, bool mortgaged, Player *owner, Player *occupying, 
						int improvements, int imprvCost):
			  	Property(number, title, cost, mBlockName, rent, purchased, mortgaged, owner, occupying),
			  	imprvCost(imprvCost), improvements(improvements) {}

AcademicBuilding::~AcademicBuilding() {}

void AcademicBuilding::improve() {
	if (improvements<5) {
		improvements += 1;
		owner->addMoney(-imprvCost);
	} else {
		cout << "Improvements already maxed!" << endl;
	}
}

void AcademicBuilding::action() {
 	for (int i=0; i<6; ++i) {
 		if((mBlockName == owner->monopolies[i]->blockName)&&(owner->monopolies[i]->full)) {
 			count = 2;
 			break;
 		} else {
 			count =1;
 		}
 	}

	int amount = rent * count;
	occupying->addMoney(-amount);
}

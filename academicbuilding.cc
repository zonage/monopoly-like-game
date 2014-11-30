#include "academicbuilding.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include <math.h> 
#include <iostream>

using namespace std;

AcademicBuilding::AcademicBuilding(string title, int cost, string mBlockName, int rent,
		int imprvCost, int improvements):
  title(title), cost(cost), mBlockName(mBlockName), rent(rent), imprvCost(imprvCost),
  improvements(improvements) {}

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
//	Human h1 = *(owner);
//	map m1 = h1.assets;
//	mBlock mb = *(m1[mBlockName]);
//	int count = mb.numP;	
//	map<string, mBlock*>  a = owner->assets["hello"];
	int count;
 	Human *hp = dynamic_cast<Human*>(owner);
	  if(hp) { 
	    
            for(int i=0; i<7; ++i) {
            if (mBlockName == owner->assets[i]->blockName) {
              count = owner->assets[i]->numP;
            }
          }
 	}	
	  else { 
	Computer *cp = dynamic_cast<Computer*>(owner);
        for(int i=0; i<7; ++i) {
          if (mBlockName == owner->assets[i]->blockName) {
            count = owner->assets[i]->numP;
          }
        }

 	}
	int amount = rent * pow(2, count);
	occupying->addMoney(-amount);
}

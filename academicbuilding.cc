#include "academicbuilding.h"
#include "player.h"
#include <math.h> 

using namespace std;

AcademicBuilding::AcademicBuilding(string title, int cost, bool purchased=false, bool mortgaged=false,
 Player *owner=NULL, Player *occupying=NULL, string mBlockName, int rent, int improvements=0, int imprvCost):
  title(title), cost(cost), mBlockName(mBlockName), rent(rent), imprvCost(imprvCost) {
 }

AcademicBuilding::~AcademicBuilding() {}

AcademicBuilding::improve() {
	if (improvements<5) {
		improvements += 1;
		owner->addMoney(-imprvCost);
	} else {
		cout << "Improvements already maxed!" << endl;
	}
}

AcademicBuilding::action() {
	int count = owner->assets[mBlockName]->numP;
	int amount = rent * pow(2, count);
	occupying->addMoney(-amount);
}

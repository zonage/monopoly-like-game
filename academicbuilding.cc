#include "academicbuilding.h"
#include "player.h"
#include <math.h> 

using namespace std;

AcademicBuilding::AcademicBuilding(string title, int cost, string mBlockName, int rent,
		int imprvCost, bool purchased, bool mortgaged, 
		int improvements, Player *owner, Player *occupying):
  title(title), cost(cost), mBlockName(mBlockName), rent(rent), imprvCost(imprvCost)
  purchased(purchased), mortgaged(mortgaged), improvements(improvements), owner(owner)
  occupying(occupying) {}

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
	int count = owner->assets[mBlockName]->numP;
	int amount = rent * pow(2, count);
	occupying->addMoney(-amount);
}

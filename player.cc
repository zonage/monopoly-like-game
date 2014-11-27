#include "player.h"
using namespace std;

// constructor
Player::Player(string name, Square *position, int money, int timCards/*, map assets */):
	name(name), money(money=1500), timCards(timcards=0) {
		map<string pname, Property *p> assets;
	}

// destructor
Player::~Player() {}

// mortchek: mortgage checker helper function
bool mortchek(Property* assets[num]) {
	int i = 0;
	while (i < num) {
	  if (assets[i]->mortgaged == true) {
	  	++i;
	  } else {
	  	return true; // there is a property that can be mortgaged
	  }
	}
	return false // all properties have already been mortgaged
}

// mortgage: iterates through players assets, asking if they would like to mortgage unmortgaged propeties
void Player::mortgage() {
	map<string pname, Property *p>::iterator i;
	string response;
	for (i = assets.begin(); i != assets.end(); ++i) {
		if (i->second->mortgaged == false) {
			cout << "Would you like to mortage" << i->first << "?" << endl;
			cin >> response;
		}
		if (response == "yes") {
			i->second->mortgaged = true;
			addMoney(0.5*(i->second->cost));
		} else if (response == "no") {
			continue;
		}
	}
}

// bankrupt: declares a person's bankruptcy
void Player::bankrupt() {
	cout << "You're bankrupt!" << endl;
}

// adds/subtracts money from player, if player's money < 0, offers mortgage option
void Player::addMoney(int amount) {
	
	money += amount;

	if (money < 0) {
	  while (mortchek(assets) && (money<0)) {
	  	this.mortgage();
	  }
	}
	if (!mortchek(assets) && (money<0)) {
		this.bankrupt();
	}
}

// roll: rolls the dice
void Player::roll()
{
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int sum = die1 + die2;
	loc += sum;
	position = theBoard.squareArr[loc];
}
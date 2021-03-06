#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "theboard.h"
#include "property.h"
using namespace std;

//TheBoard *TB;

// constructor
Player::Player(string name, string charPiece, Square * position, 
			int loc, int money, int RimCups, int TimTurns):
			name(name), charPiece(charPiece), position(position), 
			loc(loc), money(money), RimCups(RimCups), TimTurns(TimTurns) 
			{

				mBlock * monopolies[6];
				Property * pAssets[30];
				TheBoard *TB=NULL;
			}

Player::~Player() {}

int Player::deedChecker(string str) {
	for(int j=0; j<30; ++j) {
		if (pAssets[j]->title == str) {
			return j;
		}
	}

	return -1;
}

void Player::mortgage(string propertyName) {
	int loc = deedChecker(propertyName);
	if (loc>=0) {
		pAssets[loc]->mortgaged = true;
		money += (pAssets[loc]->cost)/2;
		cout << "You have mortgaged" << propertyName << endl;
	} else {
		cout << "You do not own this property." << endl;
	}
}

// roll: rolls the dice and changes the position of the player.
void Player::roll()
{
	srand(time(NULL));
	int doubles = 0;
	int die1 = 0;
	int die2 = 0;
	int sum;
	string behaviour = "normal";

	// keeps rolling until unique digits rolled, sends player to the DC Tim's Line, or let's them out
	while (die1 == die2)
	{
		if (die1 != 0)
		{
			++doubles;

			// if doubles has been rolled 3 times, sends player to DC Tim's Line
			if (doubles == 3)
			{
				behaviour = "special";
				cout << "Oh no, you rolled 3 doubles!" << endl;
				cout << "You've been sent to the DC Tim's Line!" << endl;
				TimTurns = 0;
				loc = 10;
				position = TB->squareArr[10];
				position->action();
				break;
			}

			
			cout << "Rolling again:" << endl;
		}

		die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;
		cout << "Your roll, die 1: " << die1 << " die 2: " << die2 << endl;

		// if player is in the Tim's Line, checks whether or not the rolled a double in their first roll
		if (TimTurns < 3)
		{
			behaviour = "special";
			if (die1 == die2)
			{					
				cout << "Congratulations, you've cleared the DC Tim's Line!" << endl;
				TimTurns = 3;
				break;
			}	
			else
			{
				cout << "Sorry, you did not roll doubles." << endl;
				break;
			}
		}
	}
	
	// moves player the number of spaces as their roll if no special function has occured			
	if (behaviour == "normal")
	{
		cout << "doing normal behaviour" <<endl;
		sum == die1 + die2;
		loc += sum;
		cout << TB->squareArr[0]->title << endl;
		//position = TB->squareArr[loc];
		cout << "You have moved up " << sum << " spaces." << endl;
	}
}

/*
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
*/

// bankrupt: declares a person's bankruptcy
void Player::bankrupt() {
	cout << "You're bankrupt!" << endl;
}

// adds/subtracts money from player, if player's money < 0, offers mortgage option
void Player::addMoney(int amount) {
	
	money += amount;

/*	if (money < 0) {
	  while (mortchek(assets) && (money<0)) {
	  	this.mortgage();
	  }
	}
	if (!mortchek(assets) && (money<0)) {
		this.bankrupt();
	}
*/
}

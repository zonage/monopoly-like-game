#include <iostream>
#include "computer.h"
using namespace std;

Computer::Computer(string name, string charPiece, Square *position, int loc,
		int money, int RimCups, int TimTurns): 
		Player(name, charPiece, position, loc, money, TimTurns) {
		
		//mBlock *assets[6];
	} 

Computer::~Computer() {}

void Computer::turn() {

	if ((TimTurns<3) && (RimCups>0)) {
		cout << name << "used a RimCup!" << endl;
		--RimCups;
		TimTurns = 3;
	} else if (TimTurns<3) {
		roll();
		if (TimTurns == 2)
			{
				cout << name << "overstayed his welcome at the Tims Line and pays $50 to get out" << endl;
				money -= 50;
				TimTurns = 3;
				cout << name << "has left the Tims Line" << endl;
				return;
			}	
			else if (TimTurns != 3)
			{
				++TimTurns;
				cout << "End of turn." << endl;
				return;
			}
			else
			{
				return;
			}
	} else {
	roll();
	}
}

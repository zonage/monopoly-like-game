#incude "computer.h"
using namespace std;

Computer::Computer() {
	string name = Jenkin;
	char charPiece = '@';
	Square *position;
	int loc;
	int money = 1500;
	int RimCups = 0;
	int TimTurns = 3;
}

Computer::~Computer() {}

void Computer::turn() {

	if (TimTurns<3) && (RimCups>0) {
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
				break;
			}	
			else if (TimTurns != 3)
			{
				++TimTurns;
				cout << "End of turn." << endl;
				break;
			}
			else
			{
				break;
			}
	}
}

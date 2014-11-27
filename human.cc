#include "human.h"

/ constructor
Human::Human(string name, char charPiece, Square *position, int money, int timCards/*, map assets */):
	name(name), money(money=1500), timCards(timcards=0) {
		map<string pname, Property *p> assets;
	}

Human::~Human() {}

Human::turn() {

		string answer;
		cout << "Do you want to trade? Answer: (y/n)" endl;
		cin >> answer;
		if (answer == "y")
		{
			// trade function
		}
		cout << "Do you want to mortgage? Answer: (y/n)" << endl;
		cin >> answer;
		if (answer == "y")
		{
			// mortgage function
		}
		cout << "Rolling dice!" << endl;
		currentplayer.roll();
}
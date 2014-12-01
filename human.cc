#include <iostream>
#include <string>
#include "human.h"

using namespace std;

// constructor
Human::Human(string name, string charPiece, Square *position,int loc,
	 int money, int RimCups, int TimTurns):
	Player(name, charPiece, position, loc, money, TimTurns) {

	//mBlock *assets[6];		
	
}

Human::~Human() {}

void Human::turn() {

	string answer;
	cout << "Do you want to trade? Answer: (y/n)" << endl;
	cin >> answer;

	while((answer != "y") && (answer != "n"))
	{
		cin >> answer;
	}

	if (answer == "y")
	{
		// trade function
	}

	cout << "Do you want to mortgage? Answer: (y/n)" << endl;
	cin >> answer;

	while((answer != "y") && (answer != "n"))
	{
		cin >> answer;
	}

	if (answer == "y")
	{
		// mortgage function
	}

	// checks whether or not in DC Tim's Line
	while (TimTurns < 3)
	{
		cout << "You have been in the Tim's Line for " << TimTurns << " turns." << endl;
		
		// gives the option to use Rim cup if available
		if (RimCups > 0)
		{
			cout << "Rim cups: " << RimCups << endl;
			cout << "Would you like use a Roll Up the Rim cup? Answer: (y/n)" << endl;
			cin >> answer;

			while((answer != "y") && (answer != "n"))
			{
				cin >> answer;
			}

			if (answer == "y")
			{
				cout << "You have used a Roll Up the Rim cup." << endl;
				cout << "Congratulations, you've cleared the DC Tim's Line!" << endl;
				--RimCups;
				TimTurns == 3;
				cout << "Rim cups: " << RimCups << endl;
				break;
			}
		}

		// gives option to pay
		cout << "Do you want to pay $50? Answer: (y/n)" << endl;
		cin >> answer;

		while((answer != "y") && (answer != "n"))
		{
			cin >> answer;
		}

		// pays $50 to get out of Tim's Line
		if (answer == "y")
		{
			cout << "Congratulations, you've cleared the DC Tim's Line!" << endl;
			money -= 50;
			TimTurns = 3;
			break;
		}
		else
		{
			cout << "Rolling dice!" << endl;
			roll();

			// Must pay $50 condition
			if (TimTurns == 2)
			{
				cout << "Must... get out... of Tim's Line.." << endl;
				cout << "Paid $50" << endl;
				money -=50;
				TimTurns = 3;
				cout << "Congratulations, you've cleared the DC Tim's Line!" << endl;
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

	cout << "Rolling dice!" << endl;
	roll();
	position->action();
	
	cout << "Do you want to trade? Answer: (y/n)" << endl;
	cin >> answer;

	while((answer != "y") && (answer != "n"))
	{
		cin >> answer;
	}

	if (answer == "y")
	{
		// trade function
	}

	cout << "Do you want to mortgage? Answer: (y/n)" << endl;
	cin >> answer;

	while((answer != "y") && (answer != "n"))
	{
		cin >> answer;
	}

	if (answer == "y")
	{
		// mortgage function
	}
	cout << "End of turn." << endl;
}

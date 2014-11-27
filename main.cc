/*#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "academicbuilding.h"
#include "collectosap.h"
#include "coop.h"
#include "goosenesting.h"
#include "gototims.h"
#include "gym.h"
#include "mblock.h"
#include "needleshall.h"
#include "nonproperty.h"
#include "player.h"
#include "property.h"
#include "res.h"
#include "slc.h"
#include "square.h"
#include "timsline.h"
#include "tuition.h"
*/

#include <iostream>
#include "player.h"
#include <string>

using namespace std;

square * board[40];
Player * players[4];

int main() {
//	srand(time(NULL));
	int numplayers;
	int bankrupts = 0;
	cout << "How many players? (1-4)" << endl;
	cin >> numplayers;

	// only makes players if there is at least 2
	if (numplayers < 2)
	{
		cout << "Error, not enough players. Exiting.." << endl;
		return;
	}
	else
	{

		// makes players and sets them into array: players
		for(int i = 0; i < players; ++i)
		{
			string name;
			cout << "What is your name?" << endl;
			cin >> name;
			Player * p1 = new Player(name);
			players[i] = p1;
		}

		// checking if we can do it this way <>
		for(int i = 0; i < num; i++)
		{
			cout << players[i]->name; << endl;
		}
	}

	int currentturn = 0;
	while(bankrupts != (numplayers - 1))
	{
		Player &currentplayer = *(players[currentturn]);
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

}

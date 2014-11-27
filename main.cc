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

	TheBoard *TB = new TheBoard();

	squareArr[0] = new collectOSAP;
	squareArr[1] = new AcademicBuilding("AL", 40, "Arts1", 2, 50);
	squareArr[2] = new SLC();
	squareArr[3] = new AcademicBuilding("ML", 60, "Arts1", 4, 50);
	squareArr[4] = new Tuition();
	squareArr[5] = new Res("MKV", 200, "Residences", 25);
	squareArr[6] = new AcademicBuilding("ECH", 100, "Arts2", 6, 50);
	squareArr[7] = new NeedlesHall();
	squareArr[8] = new AcademicBuilding("PAS", 100, "Arts2", 6, 50);
	squareArr[9] = new AcademicBuilding("HH", 120, "Arts2", 8, 50);
	squareArr[10] = new TimsLine();
	squareArr[11] = new AcademicBuilding("RCH", 140, "Eng", 10, 100);
	squareArr[12] = new Gym("PAC", 150, "Gyms")
	squareArr[13] = new AcademicBuilding("DWE", 140, "Eng", 10, 100);
	squareArr[14] = new AcademicBuilding("CPH", 160, "Eng", 12, 100);
	squareArr[15] = new Res("UWP", 200, "Residences", 25);
	squareArr[16] = new AcademicBuilding("LHI", 180, "Health", 14, 100);
	squareArr[17] = new SLC();
	squareArr[18] = new AcademicBuilding("BMH", 180, "Health", 14, 100);
	squareArr[19] = new AcademicBuilding("OPT", 200, "Health", 16, 100);
	squareArr[20] = new GooseNesting();
	squareArr[21] = new AcademicBuilding("EV1", 220, "Env", 18, 150);
	squareArr[22] = new NeedlesHall();
	squareArr[23] = new AcademicBuilding("EV1", 220, "Env", 18, 150);
	squareArr[24] = new AcademicBuilding("EV2", 220, "Env", 18, 150);
	squareArr[25] = new AcademicBuilding("EV3", 240, "Env", 20, 150);
	squareArr[26] = new Res("V1", 200, "Residences", 25);
	squareArr[27] = new AcademicBuilding("PHYS", 260, "Sci1", 22, 150);
	squareArr[28] = new AcademicBuilding("B1", 260, "Sci1", 22, 150);
	squareArr[29] = new Gym("CIF", 150, "Gyms")
	squareArr[30] = new AcademicBuilding("B2", 280, "Sci1", 24, 150);
	squareArr[31] = new GoToTims();
	squareArr[32] = new AcademicBuilding("EIT", 300, "Sci2", 26, 200);
	squareArr[33] = new AcademicBuilding("ESC", 300, "Sci2", 26, 200);
	squareArr[34] = new SLC();
	squareArr[35] = new AcademicBuilding("C2", 320, "Sci2", 28, 200);
	squareArr[36] = new Res("REV", 200, "Residences", 25);
	squareArr[37] = new NeedlesHall();
	squareArr[38] = new AcademicBuilding("MC", 350, "Math", 35, 200);
	squareArr[39] = new CoopFee();
	squareArr[40] = new AcademicBuilding("DC", 400, "Math", 50, 200);
	
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

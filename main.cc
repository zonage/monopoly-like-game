#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "theboard.h"
#include "academicbuilding.h"
#include "collectosap.h"
#include "coop.h"
#include "goosenesting.h"
#include "gototims.h"
#include "gym.h"
#include "mblock.h"
#include "needleshall.h"
#include "nonproperty.h"
#include "property.h"
#include "res.h"
#include "slc.h"
#include "square.h"
#include "timsline.h"
#include "tuition.h"
#include <iostream>
#include "player.h"
#include "human.h"
#include "computer.h"

using namespace std;

Square * board[40];
Player * players[6];
string pieces[7] = {"G", "B", "D", "S", "$", "L", "T"};
string compNames[6] = {"Jenkins", "Roy", "The Hulk", "Batman", "Stuff", "Turkey"};

bool checkUsed(int i, string piece)
{
	for(int j = 0; j < i; j++)
	{
		if (piece == players[j]->charPiece)
		{
		  return true;
		} else {
		  return false;
		}
	}
	return false;
}

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	int numplayers = 0;
	int compPlayers = 0;
	int bankrupts = 0;

	TheBoard *TheB = new TheBoard();
	TheB->displaymaker();
		
//	collectOSAP c;	
//	Square *p = &c;
	TheB->squareArr[0] =  new collectOSAP();
//	cout << TheB->squareArr[0]->title << endl;
	TheB->squareArr[1] = new AcademicBuilding("AL", 40, "Arts1", 2, 50);
	TheB->squareArr[2] = new SLC();
	TheB->squareArr[3] = new AcademicBuilding("ML", 60, "Arts1", 4, 50);
	TheB->squareArr[4] = new Tuition();
	TheB->squareArr[5] = new Res("MKV", 200, "Residences", 25);
	TheB->squareArr[6] = new AcademicBuilding("ECH", 100, "Arts2", 6, 50);
	TheB->squareArr[7] = new NeedlesHall();
	TheB->squareArr[8] = new AcademicBuilding("PAS", 100, "Arts2", 6, 50);
	TheB->squareArr[9] = new AcademicBuilding("HH", 120, "Arts2", 8, 50);
	TheB->squareArr[10] = new TimsLine();
	TheB->squareArr[11] = new AcademicBuilding("RCH", 140, "Eng", 10, 100);
	TheB->squareArr[12] = new Gym("PAC", 150, "Gyms");
	TheB->squareArr[13] = new AcademicBuilding("DWE", 140, "Eng", 10, 100);
	TheB->squareArr[14] = new AcademicBuilding("CPH", 160, "Eng", 12, 100);
	TheB->squareArr[15] = new Res("UWP", 200, "Residences", 25);
	TheB->squareArr[16] = new AcademicBuilding("LHI", 180, "Health", 14, 100);
	TheB->squareArr[17] = new SLC();
	TheB->squareArr[18] = new AcademicBuilding("BMH", 180, "Health", 14, 100);
	TheB->squareArr[19] = new AcademicBuilding("OPT", 200, "Health", 16, 100);
	TheB->squareArr[20] = new GooseNesting();
	TheB->squareArr[21] = new AcademicBuilding("EV1", 220, "Env", 18, 150);
	TheB->squareArr[22] = new NeedlesHall();
	TheB->squareArr[23] = new AcademicBuilding("EV2", 220, "Env", 18, 150);
	TheB->squareArr[24] = new AcademicBuilding("EV3", 240, "Env", 20, 150);
	TheB->squareArr[25] = new Res("V1", 200, "Residences", 25);
	TheB->squareArr[26] = new AcademicBuilding("PHYS", 260, "Sci1", 22, 150);
	TheB->squareArr[27] = new AcademicBuilding("B1", 260, "Sci1", 22, 150);
	TheB->squareArr[28] = new Gym("CIF", 150, "Gyms");
	TheB->squareArr[29] = new AcademicBuilding("B2", 280, "Sci1", 24, 150);
	TheB->squareArr[30] = new GoToTims();
	TheB->squareArr[31] = new AcademicBuilding("EIT", 300, "Sci2", 26, 200);
	TheB->squareArr[32] = new AcademicBuilding("ESC", 300, "Sci2", 26, 200);
	TheB->squareArr[33] = new SLC();
	TheB->squareArr[34] = new AcademicBuilding("C2", 320, "Sci2", 28, 200);
	TheB->squareArr[35] = new Res("REV", 200, "Residences", 25);
	TheB->squareArr[36] = new NeedlesHall();
	TheB->squareArr[37] = new AcademicBuilding("MC", 350, "Math", 35, 200);
	TheB->squareArr[38] = new CoopFee();
	TheB->squareArr[39] = new AcademicBuilding("DC", 400, "Math", 50, 200);


	// checks for command line arguments 
	if((argc - 1 == 2) && (argv[1] == "-load"))
	{
		string s;
		string player;
		int usepiece = 0;
		int money;
		int location;
		int DC;
		int turns;

		ifstream save(argv[2]);
		getline(save, s);
		istringstream a(s);
		a >> numplayers;


		// loads in the players
		for(int i = 0; i < numplayers; i++)
		{
			getline(save, s);
			istringstream b(s);
			b >> player;
			b >> money;
			b >> location;
			if (location == 10)
			{
				b >> DC;
				if (DC == 1)
				{
					b >> turns;
					players[i] = new Human(player, pieces[usepiece], TheB->squareArr[location], location, money, 0, turns);
					players[i]->position->occupying = players[i];
				}
				else
				{
					players[i] = new Human(player, pieces[usepiece], TheB->squareArr[location], location, money);
					players[i]->position->occupying = players[i];
				}
			}
			else
			{
				players[i] = new Human(player, pieces[usepiece], TheB->squareArr[location], location, money);
				players[i]->position->occupying = players[i];	
			}
		}

		string owner;
		int improv;
		Player * owned = NULL;
		for(int i = 0; i < 40; i ++)
		{
			if ((i == 1) || (i == 3) || (i == 6) || (i == 8) || (i == 9) || (i == 11) || (i == 13) || (i == 16) || 
				(i == 18) ||(i == 19) || (i == 21) || (i == 23) || (i == 24) ||  (i == 26) || (i == 27) || (i ==29) || 
				(i == 31) || (i == 32) || (i == 34) || (i == 37) || (i == 39) || (i == 14))
			{
				getline(save, s);
				istringstream c(s);
				c.ignore();
				c >> owner >> improv;
				for(int j = 0; j < numplayers; j++)
				{
					if (owner == players[j]->name)
					{
						owned = players[j];
					}
					else
					{
						owned = NULL;
					}
				}
				TheB->squareArr[i]->owner = owned;
				AcademicBuilding * ab = dynamic_cast<AcademicBuilding*>(TheB->squareArr[i]);
				ab->improvements = improv;
			}
			if ((i == 5) || (i == 12) || (i == 15) || (i == 25) || (i ==28) || (i == 35))
			{
				getline(save, s);
				istringstream d(s);
				d.ignore();
				d >> owner;
				for(int j = 0; j < numplayers; j++)
				{
					if (owner == players[j]->name)
					{
						owned = players[j];
					}
					else
					{
						owned = NULL;
					}
				}
				TheB->squareArr[i]->owner = owned;
			}
		}
	}
	else
	{		
		cout << "How many players? (2-6)" << endl;
		cin >> numplayers;


		// only makes players if there is at least 2
		while ((numplayers<2) || (numplayers>6))
		{
			if (numplayers<2) {
				cout << "Error, not enough players. Please enter the number of players." << endl;
				cin >> numplayers;
			} else {
				cout << "Error, too many players. Please select a number of players from 2-6." << endl;
				cin >> numplayers;
			}
			
		}
		if ((numplayers>=2)&&(numplayers<=6)) {

			// makes players and sets them into array: players
			for(int i = 0; i < numplayers; ++i)
			{
				string name;
				string controlType;
				cout << "Player details (name human/computer) ex: adam human" << endl;

				cin >> name >> controlType;
				while((controlType != "human") && (controlType != "computer"))
				{
					cout << "Please enter human/computer" << endl;
					cin >> controlType;
				}

				if (controlType == "computer") {
					int j = 0;
					while (checkUsed(i, pieces[j])) {
						++j;
					}
					players[i] = new Computer(compNames[compPlayers], pieces[j],
							TheB->squareArr[0]);
					++compPlayers;
				} else {
					string piece;
					cout << "Pick character Piece: G, B, D, S, $, L, T" << endl;
					cin >> piece;

					while (((piece!="G")&&(piece!="B")&&(piece!="D")&&(piece!="S")
						&&(piece!="$")&&(piece!="L")&&(piece!="T")) 
						|| checkUsed(i, piece))  {
						cout << "Please enter a valid character: G, B, D, S, $, L, T" << endl;
						cin >> piece;
	// do we need to check for char vs string input
					}
					players[i] = new Human(name, piece, TheB->squareArr[0]);
					players[i]->TB = TheB;
				}
			}
		}
	}
/*		// checking if we can do it this way <>
		for(int i = 0; i < num; i++)
		{
			cout << players[i]->name; << endl;
		}
*/	
	cout << TheB->squareArr[0]->title <<endl;
	int currentturn = 0;
	while(numplayers > 1)
	{
		Player &currentplayer = *(players[currentturn % 7]);
		TheB->displaymaker();
		TheB->displayprinter();
	//	cout << TheB->squareArr[0]->title <<endl;
		currentplayer.turn();
	}
}
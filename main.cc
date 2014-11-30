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
		Human
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
//	srand(time(NULL));
	int numplayers = 0;
	int compPlayers = 0;
	int bankrupts = 0;

	TheBoard *TB = new TheBoard();
	TB->displaymaker();

	TB->squareArr[0] = new collectOSAP();
	TB->squareArr[1] = new AcademicBuilding("AL", 40, "Arts1", 2, 50);
	TB->squareArr[2] = new SLC();
	TB->squareArr[3] = new AcademicBuilding("ML", 60, "Arts1", 4, 50);
	TB->squareArr[4] = new Tuition();
	TB->squareArr[5] = new Res("MKV", 200, "Residences", 25);
	TB->squareArr[6] = new AcademicBuilding("ECH", 100, "Arts2", 6, 50);
	TB->squareArr[7] = new NeedlesHall();
	TB->squareArr[8] = new AcademicBuilding("PAS", 100, "Arts2", 6, 50);
	TB->squareArr[9] = new AcademicBuilding("HH", 120, "Arts2", 8, 50);
	TB->squareArr[10] = new TimsLine();
	TB->squareArr[11] = new AcademicBuilding("RCH", 140, "Eng", 10, 100);
	TB->squareArr[12] = new Gym("PAC", 150, "Gyms");
	TB->squareArr[13] = new AcademicBuilding("DWE", 140, "Eng", 10, 100);
	TB->squareArr[14] = new AcademicBuilding("CPH", 160, "Eng", 12, 100);
	TB->squareArr[15] = new Res("UWP", 200, "Residences", 25);
	TB->squareArr[16] = new AcademicBuilding("LHI", 180, "Health", 14, 100);
	TB->squareArr[17] = new SLC();
	TB->squareArr[18] = new AcademicBuilding("BMH", 180, "Health", 14, 100);
	TB->squareArr[19] = new AcademicBuilding("OPT", 200, "Health", 16, 100);
	TB->squareArr[20] = new GooseNesting();
	TB->squareArr[21] = new AcademicBuilding("EV1", 220, "Env", 18, 150);
	TB->squareArr[22] = new NeedlesHall();
	TB->squareArr[23] = new AcademicBuilding("EV2", 220, "Env", 18, 150);
	TB->squareArr[24] = new AcademicBuilding("EV3", 240, "Env", 20, 150);
	TB->squareArr[25] = new Res("V1", 200, "Residences", 25);
	TB->squareArr[26] = new AcademicBuilding("PHYS", 260, "Sci1", 22, 150);
	TB->squareArr[27] = new AcademicBuilding("B1", 260, "Sci1", 22, 150);
	TB->squareArr[28] = new Gym("CIF", 150, "Gyms");
	TB->squareArr[29] = new AcademicBuilding("B2", 280, "Sci1", 24, 150);
	TB->squareArr[30] = new GoToTims();
	TB->squareArr[31] = new AcademicBuilding("EIT", 300, "Sci2", 26, 200);
	TB->squareArr[32] = new AcademicBuilding("ESC", 300, "Sci2", 26, 200);
	TB->squareArr[33] = new SLC();
	TB->squareArr[34] = new AcademicBuilding("C2", 320, "Sci2", 28, 200);
	TB->squareArr[35] = new Res("REV", 200, "Residences", 25);
	TB->squareArr[36] = new NeedlesHall();
	TB->squareArr[37] = new AcademicBuilding("MC", 350, "Math", 35, 200);
	TB->squareArr[38] = new CoopFee();
	TB->squareArr[39] = new AcademicBuilding("DC", 400, "Math", 50, 200);
	
	// checks for command line arguments 
	if((argc - 1 == 2) && (argv[1] == "-load"))
	{
		string s;
		string player;
		int usepiece = 0;
		int money;
		int location;
		int DC?;
		int turns;

		ifstream save(argv[2]);z
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
				b >> DC?;
				if (DC? == 1)
				{
					b >> turns;
					players[i] = new Human(player, pieces[usepiece], TB->squareArr[location], location, money, 0, turns);
					player[i]->position->occupying = player[i];
				}
				else
				{
					players[i] = new Human(player, pieces[usepiece], TB->squareArr[location], location, money,);
					player[i]->position->occupying = player[i];
				}
			}
			else
			{
				players[i] = new Human(player, pieces[usepiece], TB->squareArr[location], location, money,);
				player[i]->position->occupying = player[i];	
			}
		}

		string owner;
		int improv;
		Square * owned = NULL;
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
				TB->squareArr[i]->owner = owned;
				AcademicBuilding * ab = dynamic_cast<AcademicBuilding*>(TB->squareArr[i])
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
				TB->squareArr[i]->owner = owned;
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
							TB->squareArr[0]);
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
					players[i] = new Human(name, piece, TB->squareArr[0]);
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
	int currentturn = 0;
	while(numplayers > 1)
	{
		Player &currentplayer = *(players[currentturn % 7]);
		TB->displayprinter();
		currentplayer.turn();
	}
}

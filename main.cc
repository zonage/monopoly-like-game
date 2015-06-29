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

void buy(Player *p1, Square * p)
{
	p->owner = p1;
}

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
int save = 0;

void roll(Player &currentplayer) {
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
				currentplayer.TimTurns = 0;
				currentplayer.loc = 10;
				currentplayer.position = board[10];
				currentplayer.position->action();
				break;
			}

			
			cout << "Rolling again:" << endl;
		}

		die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;
		cout << "Your roll, die 1: " << die1 << " die 2: " << die2 << endl;

		// if player is in the Tim's Line, checks whether or not the rolled a double in their first roll
		if (currentplayer.TimTurns < 3)
		{
			behaviour = "special";
			if (die1 == die2)
			{					
				cout << "Congratulations, you've cleared the DC Tim's Line!" << endl;
				currentplayer.TimTurns = 3;
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
		sum = die1 + die2;
		currentplayer.loc += sum;
		currentplayer.position = board[currentplayer.loc];
		cout << "You have moved up " << sum << " spaces." << endl;
	}
}


int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	int numplayers = 0;
	int compPlayers = 0;
	int bankrupts = 0;

	//boardoard boardo;
	//boardoard *board = &boardo;
	//board->displaymaker();
	
	TheBoard *TheB = new TheBoard();
	TheBoard TheBo;
	TheBoard *TheB = &TheBo;
	TheB->displaymaker();
	TheB->displayprinter();
		
	collectOSAP C;	
	Square *pC = &C;
	board[0] = pC;
	
	AcademicBuilding AL("AL", 40, "Arts1", 2, 50);
	Square *pAL = &AL;
	board[1] = pAL;

	SLC S;
	
	Square *pS = &S;
	board[2] = pS;

	AcademicBuilding ML("ML", 60, "Arts1", 4, 50);	
	Square *pML = &ML;
	board[3] = pML;

	Tuition T;
	Square *pT = &T;
	board[4] = pT;
	
	Res MKV("MKV", 200, "Residences", 25);
	Square *pMKV = &MKV;
	board[5] = pMKV;

	AcademicBuilding ECH("ECH", 100, "Arts2", 6, 50);
	Square *pECH = &ECH;
	board[6] = pECH;

	NeedlesHall NH;
	Square *pNH = &NH;
	board[7] = pNH;
	
	AcademicBuilding PAS("PAS", 100, "Arts2", 6, 50);
	Square * pPAS = &PAS;
	board[8] = pPAS;

	AcademicBuilding HH("HH", 120, "Arts2", 8, 50);
	Square *pHH = &HH;
	board[9] = pHH;

 	TimsLine TL;
 	Square *pTL = &TL;
 	board[10] = pTL;

	AcademicBuilding RCH("RCH", 140, "Eng", 10, 100);
	Square *pRCH = &RCH;
	board[11] = pRCH;

	Gym PAC("PAC", 150, "Gyms");
	Square *pPAC = &PAC;
	board[12] = pPAC;

	AcademicBuilding DWE("DWE", 140, "Eng", 10, 100);
	Square *pDWE = &DWE;
	board[13] = pDWE; 

	AcademicBuilding CPH("CPH", 160, "Eng", 12, 100);
	Square *pCPH = &CPH;
	board[14] = pCPH;

	Res UWP("UWP", 200, "Residences", 25);
	Square *pUWP = &UWP;
	board[15] = pUWP;

	AcademicBuilding LHI("LHI", 180, "Health", 14, 100);
	Square *pLHI = &LHI;
	board[16] = pLHI;

	SLC S2;
	Square *pS2 = &S2;
	board[17] = pS2;

	AcademicBuilding BMH("BMH", 180, "Health", 14, 100);
	Square *pBMH = &BMH;
	board[18] = pBMH; 

	AcademicBuilding OPT("OPT", 200, "Health", 16, 100);
	Square *pOPT = &OPT;
	board[19] = pOPT;

	GooseNesting GN;
	Square *pGN = &GN;
	board[20] = pGN;

	AcademicBuilding EV1("EV1", 220, "Env", 18, 150);
	Square *pEV1 = &EV1;
	board[21] = pEV1;

	NeedlesHall NH2;
	Square *pNH2 = &NH2;
	board[22] = pNH2;

	AcademicBuilding EV2("EV2", 220, "Env", 18, 150);
	Square *pEV2 =&EV2;
	board[23] = pEV2;
	TheB->squareArr[0] = pC;
	
	AcademicBuilding AL("AL", 40, "Arts1", 2, 50);
	Square *pAL = &Al;
	TheB->squareArr[1] = pAl;

	SLC S;
	Square *pS = &S;
	TheB->squareArr[2] = pS;

	AcademicBuilding ML("ML", 60, "Arts1", 4, 50);	
	Square *pML = &ML;
	TheB->squareArr[3] = pML;

	Tuition T;
	Square *pT = &T;
	TheB->squareArr[4] = pT;
	
	Res MKV("MKV", 200, "Residences", 25);
	Square *pMKV = &MKV;
	TheB->squareArr[5] = pMKV;

	AcademicBuilding ECH("ECH", 100, "Arts2", 6, 50);
	Square *pECH = &ECH;
	TheB->squareArr[6] = pECH;

	NeedlesHall NH;
	Square *pNH = &NH;
	TheB->squareArr[7] = pNH;
	
	AcademicBuilding PAS("PAS", 100, "Arts2", 6, 50);
	Square * pPAS = &PAS;
	TheB->squareArr[8] = pPAS;

	AcademicBuilding HH("HH", 120, "Arts2", 8, 50);
	Square *pHH = &HH;
	TheB->squareArr[9] = pHH;

 	TimsLine T;
 	Square *pT = &T;
 	TheB->squareArr[10] = pT;

	AcademicBuilding RCH("RCH", 140, "Eng", 10, 100);
	Square *pRCH = &RCH;
	TheB->squareArr[11] = pRCH;

	Gym PAC("PAC", 150, "Gyms");
	Square *pPAC = &PAC;
	TheB->squareArr[12] = pPAC;

	AcademicBuilding DWE("DWE", 140, "Eng", 10, 100);
	Square *pDWE = &DWE;
	TheB->squareArr[13] = pDWE; 

	AcademicBuilding CPH("CPH", 160, "Eng", 12, 100);
	Square *pCPH = &CPH;
	TheB->squareArr[14] = pCPH;

	Res UWP("UWP", 200, "Residences", 25);
	Square *pUWP = &UWP;
	TheB->squareArr[15] = pUWP;

	AcademicBuilding LHI("LHI", 180, "Health", 14, 100);
	Square *pLHI = &LHI;
	TheB->squareArr[16] = pLHI;

	SLC S2;
	Square *pS2 = &S2;
	TheB->squareArr[17] = pS2;

	AcademicBuilding BMH("BMH", 180, "Health", 14, 100);
	Square *pBMH = &BMH;
	TheB->squareArr[18] = pBMH; 

	AcademicBuilding OPT("OPT", 200, "Health", 16, 100);
	Square *pOPT = &OPT;
	TheB->squareArr[19] = pOPT;

	GooseNesting GN;
	Square *pGN = &GN;
	TheB->squareArr[20] = pGN;

	AcademicBuilding EV1("EV1", 220, "Env", 18, 150);
	Square *pEV1 = &EV1;
	TheB->squareArr[21] = pEV1;

	NeedlesHall NH2;
	Square *pNH2 = &NH2;
	TheB->squareArr[22] pNH2;

	AcademicBuilding EV2("EV2", 220, "Env", 18, 150);
	Square *pEV2 =&EV2;
	TheB->squareArr[23] = pEV2;

	AcademicBuilding EV3("EV3", 240, "Env", 20, 150);
	Square *pEV3 = &EV3;
	board[24] = pEV3;

	Res V1("V1", 200, "Residences", 25);
	Square *pV1 = &V1;
	board[25] = pV1;

	AcademicBuilding PHYS("PHYS", 260, "Sci1", 22, 150);
	Square *pPHYS = &PHYS;
	board[26] = pPHYS;

	AcademicBuilding B1("B1", 260, "Sci1", 22, 150);
	Square *pB1 = &B1;
	board[27] = pB1;
	
	Gym CIF("CIF", 150, "Gyms");
	Square *pCIF = &CIF;
	board[28] = pCIF;

	AcademicBuilding B2("B2", 280, "Sci1", 24, 150);
	Square * pB2 = &B2;
	board[29] = pB2;

	GoToTims GTT;
	Square *pGTT = &GTT;
	board[30] = pGTT;

	AcademicBuilding EIT("EIT", 300, "Sci2", 26, 200);
	Square *pEIT = &EIT;
	board[31] = pEIT;

	AcademicBuilding ESC("ESC", 300, "Sci2", 26, 200);
	Square *pESC = &ESC;
	board[32] = pESC;

	SLC S3;
	Square *pS3 = &S3;
	board[33] = pS3;

	AcademicBuilding C2("C2", 320, "Sci2", 28, 200);
	Square * pC2 = &C2;
	board[34] = pC2;

	Res REV("REV", 200, "Residences", 25);
	Square *pREV = &REV;
	board[35] = pREV; 

	NeedlesHall NH3;
	Square *pNH3 = &NH3;
	board[36] = pNH3;

	AcademicBuilding MC("MC", 350, "Math", 35, 200);
	Square *pMC = &MC;
	board[37] = pMC;

	CoopFee CooP;
	Square * pCoop = &CooP;
	board[38] = pCoop;

	AcademicBuilding DC("DC", 400, "Math", 50, 200);
	Square *pDC = &DC;
	board[39] = pDC; 

	// checks for command line arguments 
	string load = "-load";
	if((argc - 1 == 2) && (argv[1] == load))
	{
	save= 1;
		cout << "did this" << endl;
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
					players[i] = new Human(player, pieces[usepiece], board[location], location, money, 0, turns);
					players[i]->position->occupying = players[i];
					players[i]->TB = board[0];
				}
				else
				{
					players[i] = new Human(player, pieces[usepiece], board[location], location, money);
					players[i]->position->occupying = players[i];
					players[i]->TB = board[0];
				}
			}
			else
			{
				players[i] = new Human(player, pieces[usepiece], board[location], location, money);
				players[i]->position->occupying = players[i];	
				players[i]->TB = board[0];
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
				board[i]->owner = owned;
				AcademicBuilding * ab = dynamic_cast<AcademicBuilding*>(board[i]);
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
				board[i]->owner = owned;
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
							board[0]);
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
					players[i] = new Human(name, piece, board[0]);
					players[i]->TB = board[0];
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
//	cout << board[0]->title <<endl;
	int currentturn = 0;
	while(numplayers > 1)
	{
		Player &currentplayer = *(players[currentturn % 7]);
	//	cout << board[0]->title <<endl;
		cout << "Player: " << currentplayer.name << "turn" <<endl;
		string answer;
		cout << "Do you want to trade ? Answer: (y/n)" << endl;
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

		roll(currentplayer);

		if (Property* p11 = dynamic_cast<Property *>(currentplayer.position)) {
			if (currentplayer.position->purchased == false) {
				string answer;
				cout << "Do you want to buy" << currentplayer.position->title << endl;
				cin >> answer;
				if (answer == "y") {
					buy(players[currentturn % 7], currentplayer.position);
					cout << "Congratz, you just bought: " << currentplayer.position->title << endl;
				}
				else { 
					cout << "you didn't buy it" << endl;
				}
			} 
			else {
				cout << "This property has already been purchased." << endl;
				cout << "you must pay rent" << endl;
				cout << "You have lost $" << currentplayer.position->rent << endl;
			}
		} 
		else {
		int thing;
			thing = rand() % 1 + 5;
			if (thing == 1) {
				cout << "You've just been attacked by geese" << endl;
			}
			if (thing == 2) {
				cout << "You've received a Rim Cup" << endl;
				currentplayer.RimCups++;
			}
			if (thing == 3) {
				cout << "You've just been sent been sent to the Tim's Line" << endl;
				currentplayer.position = board[10];
			}
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
		currentturn++;
	}
}
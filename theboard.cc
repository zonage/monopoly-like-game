#include "theboard.h"
#include <iostream>
#include <string>

using namespace std;

TheBoard::TheBoard() {
	Square *squareArr[40];
	Player *playerArr[6];
}

TheBoard::~TheBoard(){
	delete [] playerArr;
	delete [] squareArr;
}



// makes the display
void TheBoard::displaymaker()
{	
	// makes everything on the grid a space
	for(int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 89; ++j)
		{
			display[i][j] = " ";
		}
	}
	
	// draws in the rows
	for (int i = 0; i < 56; i += 5)
	{
		for (int j = 0; j < 89; ++j)
		{
			display[i][j] = "_";
		}
	}
	
	// draws improvement lines for top row
	for (int j = 9; j < 81; j++)
	{
		if ((j % 24) < 16)
		{
			display[2][j] = "-";
		}
	}
	
	// draws improvement lines for the bottom row
	for (int j = 9; j < 81; j++)
	{
		if ((((j % 24) > 8) && ((j % 24) < 16)) 
			|| ((j % 56) > 16) && ((j % 56) < 24))
		{
			display[52][j] = "-";
		}
	}

	
	// draws improvement lines for the columns
	for (int i = 2; i < 53; i += 5)
	{
	   for(int j = 1; j < 88; ++j)
	   {
	      if ((i == 7) || (i == 12) || (i == 22) || (i == 32) ||
	      	(i == 42) || (i == 47))
	      {
	         display[i][j] = "-";
	      }
	   }
	}
	//draws in the columns
	for (int i = 1; i < 56; i++)
	{
		for (int j = 0; j < 89; j += 8)
		{
			display[i][j] = "|";
		}
	}
	
	// fix bottom row top
	for(int j = 16; j < 80; j += 8)
	{
		display[50][j] = "_";
	}
	
	// makes centre blank
	for(int i = 6; i < 50; i++)
	{
		for (int j = 9; j < 80; ++j)
		{
			display[i][j] = " ";
		}
	}
	// writes goose nesting
	string g = "Goose";
	string n = "Nesting";
	for (int j = 1; j < 6; j++)
	{
		display[1][j] = g[j - 1];
	}
	for (int j = 1; j < 8; j++)
	{
		display[2][j] = n[j - 1];
	}
	
	// writes Needles Hall
	g = "NEEDLES";
	n = "HALL";
	for (int j = 17; j < 24; j++)
	{
		display[1][j] = g[j - 17];
	}
	for (int j = 17; j < 21; j++)
	{
		display[2][j] = n[j - 17];
	}
	
	// writes V1
	g = "V1";
	n = "Hall";
	for (int j = 41; j < 43; j++)
	{
		display[1][j] = g[j - 41];
	}
	// writes CIF
	g = "CIF";
	n = "Hall";
	for (int j = 65; j < 68; j++)
	{
		display[1][j] = g[j - 65];
	}
	
	// writes Go To Tims
	g = "GO TO";
	n = "TIMS";
	for (int j = 81; j < 86; j++)
	{
		display[1][j] = g[j - 81];
	}
	for (int j = 81; j < 85; j++)
	{
		display[2][j] = n[j - 81];
	}
	
	// writes EIT and OPT
	g = "OPT";
	n = "EIT";
	for (int j = 1; j < 4; j++)
	{
		display[8][j] = g[j - 1];
		display[8][j + 80] = n[j - 1];
	}
	
	// writes BMH and ESC
	g = "BMH";
	n = "ESC";
	for (int j = 1; j < 4; j++)
	{
		display[13][j] = g[j - 1];
		display[13][j + 80] = n[j - 1];
	}
	
	// writes SLC
	g = "SLC";
	n = "OPT";
	for (int j = 1; j < 4; j++)
	{
		display[16][j] = g[j - 1];
		display[16][j + 80] = g[j - 1];
	}
	
	// writes LHI and C2
	g = "LHI";
	n = "C2";
	for (int j = 1; j < 4; j++)
	{
		display[23][j] = g[j - 1];
		if (j < 3) 
		{
			display[23][j + 80] = n[j - 1];
		}
	}
		// writes SLC
	g = "UWP";
	n = "REV";
	for (int j = 1; j < 4; j++)
	{
		display[26][j] = g[j - 1];
		display[26][j + 80] = n[j - 1];
	}
	// writes CPH and NEEDLES Hall
	g = "CPH";
	n = "NEEDLES HALL";
	for (int j = 1; j < 8; j++)
	{
		display[31][j + 80] = n[j -1];
		if (j < 4) 
		{
			display[33][j] = g[j - 1];
		}
		if (j < 5) 
		{
			display[32][j + 80] = n[j + 7];
		}
		if (j >= 5)
		{
			display[32][j + 80] = " ";
		}
	}
	
	// writes DWE and MC
	g = "DWE";
	n = "MC";
	for (int j = 1; j < 8; j++)
	{
		display[37][j + 80] = "-";
		display[37][j] = "-";
		if (j < 4) 
		{
			display[38][j] = g[j - 1];
		}
		if (j < 3) 
		{
			display[38][j + 80] = n[j - 1];
		}
	}
	
	// writes PAC and COOP FEE
	g = "PAC";
	n = "COOP FEE";
	for (int j = 1; j < 8; j++)
	{
		display[42][j] = " ";
		if (j < 4) 
		{
			display[41][j] = g[j - 1];
			display[42][j + 80] = n[j + 4];
		}
		if (j < 5) 
		{
			display[41][j + 80] = n[j - 1];
			display[42][j + 83] = " "; 
		}
	}
	
	// writes RCH and DC
	g = "RCH";
	n = "DC";
	for (int j = 1; j < 4; j++)
	{
		display[48][j] = g[j - 1];
		if (j < 3) 
		{
			display[48][j + 80] = n[j - 1];
		}
	}
	
	// writes RCH and DC
	g = "DC Tims Line";
	n = "COLLECT OSAP";
	for (int j = 1; j < 8; j++)
	{
		display[51][j] = g[j - 1];
		display[51][j + 80] = n[j - 1];
		if (j < 5) 
		{
			display[52][j] = g[j + 7];
			display[52][j + 80] = n[j + 7];
		}
	}
	
	// writes ownable buildings in top row
	g = "         EV1             EV2     EV3             PHYS    B1              B2";
	for (int j = 9; j < 80; j++)
	{
		if ((j < 12) && (j > 8))
		{
			display[3][j] = g[j];
		}
		if ((j > 24) && (j < 28))
		{
			display[3][j] = g[j];
		}
		if ((j > 32) && (j < 36))
		{
			display[3][j] = g[j];
		}
		if ((j > 48) && (j < 53))
		{
			display[3][j] = g[j];
		}
		if ((j > 56) && (j < 59))
		{
			display[3][j] = g[j];
		}
		if ((j > 72) && (j < 75))
		{
			display[3][j] = g[j];
		}
	}

	// writes ownable buildings in bottom row
	g = "         HH      PAS             ECH                     ML              AL";
	for (int j = 9; j < 80; j++)
	{
		if ((j < 12) && (j > 8))
		{
			display[53][j] = g[j];
		}
		if ((j > 16) && (j < 20))
		{
			display[53][j] = g[j];
		}
		if ((j > 32) && (j < 36))
		{
			display[53][j] = g[j];
		}
		if ((j > 56) && (j < 59))
		{
			display[53][j] = g[j];
		}
		if ((j > 72) && (j < 75))
		{
			display[53][j] = g[j];
		}
	}
	
	// writes unownable buildings in bottom row
	g = "                         NEEDLES         MKV     TUITION         SLC";
	n = "                         HALL";
	for (int j = 9; j < 80; j++)
	{
		if ((j > 24) && (j < 32))
		{
			display[51][j] = g[j];
		}
		if ((j > 40) && (j < 44))
		{
			display[51][j] = g[j];
		}
		if ((j > 48) && (j < 56))
		{
			display[51][j] = g[j];
		}
		if ((j > 64) && (j < 68))
		{
			display[51][j] = g[j];
		}
		if ((j > 24) && (j < 29))
		{
			display[52][j] = n[j];
		}
	}
}

void TheBoard::displayprinter()
{
	// prints display
	for(int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 89; ++j)
		{
			cout << display[i][j];
		}
		cout << endl;
	}
}

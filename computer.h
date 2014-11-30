#ifndef __COMPUTER_H__
#define __COMPUTER_H__ 
#include "player.h"
#include "mblock.h"

class Computer: public Player 
{
public: 
	mBlock *assets[];
	void turn();
 	Computer(std::string name = "fred", std::string charPiece = "D", Square *position = NULL, int loc=0,
	int money=1500, int RimCups=0, int TimTurns=0); 
	~Computer();
};


#endif

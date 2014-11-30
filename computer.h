#ifndef __COMPUTER_H__
#define __COMPUTER_H__ 
#include "player.h"
#include "mblock.h"

class Computer: public Player 
{
public: 
	mBlock *assets[];
	void turn();
 	Computer(std::string name,std:: string charPiece, Square *position, int loc=0,
	int money=1500, int RimCups=0, int TimTurns=0); 
	~Computer();
};


#endif

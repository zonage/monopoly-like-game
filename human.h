#ifndef __HUMAN_H__
#define __HUMAN_H__ 
#include <string>
#include "player.h"
#include "square.h"
#include "mblock.h"
class Property;

class Human: public Player {
public:

	Human(std::string name = "fred", std::string charPiece = "D", Square *position = NULL,
	int loc=0, int money=1500, int RimCups=0, int TimTurns=3);
	~Human();
	virtual void turn();
};

#endif

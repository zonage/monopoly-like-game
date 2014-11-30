#ifndef __HUMAN_H__
#define __HUMAN_H__ 
#include <string>
#include "player.h"
#include "square.h"
#include "mblock.h"
class Property;

class Human: public Player {
public:
	std::string name;
	std::string charPiece;
	  Square* position;
          int loc;
          int money;
          int RimCups;
          int TimTurns;
        mBlock assets[];
	Human(std::string name, std::string charPiece, Square *position,
	int loc=0, int money=1500, int RimCups=0, int TimTurns=3);
	~Human();
	virtual void turn();
};

#endif

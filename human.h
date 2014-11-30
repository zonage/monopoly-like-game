#ifndef __HUMAN_H__
#define __HUMAN_H__ 
#include <string>
#include "player.h"
#include "square.h"
class Property;

class Human: public Player {
public:
	Human(std::string name, char charPiece, Square *position=TB->squareArr[0], 
	int money=1500, int RimCups=0);
	~Human();
	virtual void turn();
};

#endif

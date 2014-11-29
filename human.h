#ifndef __HUMAN_H__
#define __HUMAN_H__ 
#include <string>
#include "player.h"
#include "square.h"

class human: public Player {
public:
	human(string name, char charPiece, Square *position, int money, int RimCups/*, map assets */);
	~human();
	virtual void turn();
};

#endif
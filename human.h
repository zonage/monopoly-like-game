#ifndef __HUMAN_H__
#define __HUMAN_H__ 
#include "player.h"

class human: public Player {
public:
	human(string name, char charPiece, Square *position, int money, int timCards/*, map assets */);
	~human();
	virtual void turn();
};

#endif
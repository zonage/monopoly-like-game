#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <map>
#include "square.h"

class Player {
	public:
	std::string name;
	char charPiece;
	Square* position;
	int loc;
	int money;
	int RimCups;
	int TimTurns = 3;
	std::map assets;

	virtual void turn()=0;
	void addMoney(int);
	void mortgage();
	void bankrupt();
	void roll();
	Player();
	~Player();
};

#endif
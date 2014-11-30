#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <map>
#include "square.h"
#include "mblock.h"
class Property;

class Player {
	public:
	std::string name;
	std::string charPiece;
	Square* position;
	int loc;
	int money;
	int RimCups;
	int TimTurns;
//	typedef std::map<std::string, int> assets;

	virtual void turn()=0;
	void addMoney(int);
	void mortgage();
	void bankrupt();
	void roll();
	void trade();
	Player(std::string name, std::string charPiece, Square * position, int loc
			, int money, int RimCups, int TimTurns);
	virtual ~Player();
};

#endif

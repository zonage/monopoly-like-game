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
	mBlock * monopolies[];
	Property * pAssets[];

	TheBoard *TB;

	virtual void turn()=0;
	void addMoney(int);
	void mortgage(std::string);
	void bankrupt();
	void roll();
	void trade();

	int deedChecker(std::string);

	Player(std::string name = "fred", std::string charPiece = "D", Square * position=NULL,
		int loc=0, int money=1500, int RimCups=0, int TimTurns=3);

	virtual ~Player();
};

#endif

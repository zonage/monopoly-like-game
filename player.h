#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <map>
class Sqaure;

class Player {
	public:
	std::string name;
	Square* position;
	int loc;
	int money;
	int timCards;
	int timturns = 3;
	std::map assets;

	void addMoney(int);
	void mortgage();
	void bankrupt();
	void roll();
	Player();
	~Player();
};

#endif
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <map>
class Sqaure;

class Player {
	public:
	std::string name;
	Square* position;
	int money;
	int timCards;
	std::map assets;

	void virtual turn() =0;
	void addMoney(int);
	void mortgage();
	void bankrupt();
	Player();
	~Player();
};

#endif
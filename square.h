#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <string>
class Player;
class TheBoard;

class Square {

	public:

	int number;
	TheBoard *TB;	

	std::string title;
	int cost;
	std::string mBlockName;
	int rent;

	bool purchased;
	bool mortgaged;
	Player *owner;
	Player *occupying;

	Square(std::string title="", int cost=0, std::string mBlockName="", 
		int rent=0, int number=0, bool purchased=0, bool mortgaged=0,
		 Player *owner=NULL, Player *occupying=NULL, TheBoard *TB=NULL);
	~Square();
	virtual void action()=0;
};

#endif

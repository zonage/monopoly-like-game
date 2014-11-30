#ifndef __THEBOARD_H__
#define __THEBOARD_H__
#include <string>
#include "square.h"

class Player;

class TheBoard {
public:

	bool newboard;
	Square *squareArr[];
	Player *playerArr[];
	std::string display[][];

	void displaymaker();
	void displayprinter();
	TheBoard();
	~TheBoard();

};

#endif

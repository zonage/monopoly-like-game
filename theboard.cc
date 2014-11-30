#include "theboard.h"

TheBoard::TheBoard() {
	Square *squareArr[40];
	Player *playerArr[4];
}

TheBoard::~TheBoard(){
	delete [] playerArr;
	delete [] squareArr;
}


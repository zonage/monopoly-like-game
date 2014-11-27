#ifndef __THEBOARD_H__
#define __THEBOARD_H__
#include <string>

class TheBoard {
public:

	bool newboard;
	Square *[40];
	Player *[4];

	theboard();
	~theboard();

};

#endif

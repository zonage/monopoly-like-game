#ifndef __MBLOCK_H__
#define __MBLOCK_H__
#include <string>

class mBlock {
public:
	int numP;
	Property *p1;
	Property *p2;
	Property *p3;

	mBlock(int numP, Property *p1, Property *p2, Property *p3);
	~mBlock();

};

#endif
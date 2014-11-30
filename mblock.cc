#include "mblock.h"
using namespace std;

mBlock::mBlock(string blockName, int numP, bool full, 
	Property *p1, Property *p2, Property *p3): 
	blockName(blockName), numP(numP), full(full), p1(p1), p2(p2), p3(p3) {}

mBlock::~mBlock() {}


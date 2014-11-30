#ifndef __MBLOCK_H__
#define __MBLOCK_H__
#include <string>
class Property;

class mBlock {
public:
	std::string blockName;
	bool full;
 	int numP;
	Property *p1;
	Property *p2;
	Property *p3;

	mBlock(std::string blockName, bool full=false, int numP=0, 
		Property *p1=NULL, Property *p2=NULL, Property *p3=NULL);
	~mBlock();

};

#endif

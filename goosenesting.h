#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"


class GooseNesting: public NonProperty
{
public:
	Player * occupying;
	virtual void action();
	~GooseNesting();
};

#endif

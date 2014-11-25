#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__
#include <iostream>
#include "non-property.h"
#include "player.h"


class GooseNesting: public non-property
{
public:
	player * occupying;
	virtual void action();
	~GooseNesting();
};

#endif
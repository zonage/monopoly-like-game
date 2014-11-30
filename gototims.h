#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"

class GoToTims: public NonProperty
{
public:
	Player * occupying;
	virtual void action();
	~GoToTims();
};

#endif

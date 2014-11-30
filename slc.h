#ifndef __SLC_H__
#define __SLC_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"


class SLC: public NonProperty
{
public:
	Player * occupying;
	virtual void action();
	~SLC();
};

#endif

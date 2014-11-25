#ifndef __SLC_H__
#define __SLC_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"


class SLC: public non-property
{
public:
	player * occupying;
	virtual void action();
	~SLC();
};

#endif
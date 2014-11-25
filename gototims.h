#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"

class GoToTims: public non-property
{
public:
	player * occupying;
	virtual void action();
	~GoToTims();
};

#endif
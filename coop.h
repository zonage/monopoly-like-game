#ifndef __COOPFEE_H__
#define __COOPFEE_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"


class CoopFee: public NonProperty
{
public:
	Player * occupying;
	virtual void action();
	~CoopFee();
};

#endif

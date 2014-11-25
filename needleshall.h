#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"


class NeedlesHall: public non-property
{
public:
	player * occupying;
	virtual void action();
	~NeedlesHall();
};

#endif
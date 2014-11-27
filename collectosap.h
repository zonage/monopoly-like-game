#ifndef __COLLECTOSAP_H__
#define __COLLECTOSAP_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"


class collectOSAP: public non-property
{
public:
	player * occupying;
	virtual void action();
	~collectOSAP();
};

#endif
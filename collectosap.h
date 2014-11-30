#ifndef __COLLECTOSAP_H__
#define __COLLECTOSAP_H__
#include "nonproperty.h"
#include "player.h"


class collectOSAP: public NonProperty
{
public:
	Player * occupying;
	virtual void action();

	//collectOSAP();
	~collectOSAP();
};

#endif

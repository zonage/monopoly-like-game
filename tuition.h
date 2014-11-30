#ifndef __TUITION_H__
#define __TUITION_H__
#include <iostream>
#include "nonproperty.h"
#include <string>
#include "player.h"


class Tuition: public NonProperty
{
public:
	Player * occupying;
	virtual void action();
	~Tuition();
};

#endif

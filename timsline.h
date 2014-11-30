#ifndef __TIMSLINE_H__
#define __TIMSLINE_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"

class TimsLine: public NonProperty
{
public:
	Player * occupying;
	int cupsinplay;
	virtual void action();
	~TimsLine();
};

#endif

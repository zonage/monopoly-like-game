#ifndef __TIMSLINE_H__
#define __TIMSLINE_H__
#include <iostream>
#include "nonproperty.h"
#include "player.h"

class TimsLine: public non-property
{
public:
	player * occupying;
	int cupsinplay;
	virtual void action();
	~TimsLine();
};

#endif
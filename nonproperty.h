#ifndef __NONPROPERTY_H__
#define __NONPROPERTY_H__
#include "square.h"

class NonProperty: public square
{
public:
	virtual void action() = 0;
	virtual ~NonProperty();
};

#endif
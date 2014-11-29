#include <iostream>
#include "collectosap.h"

// collectOSAP: increases the player's money by $200
void collectOSAP::action()
{
	occupying->money += 200;
}

// constructor
//collectOSAP::collectOSAP() {}

// destructor
collectOSAP::~collectosap()
{
	delete occupying;
}
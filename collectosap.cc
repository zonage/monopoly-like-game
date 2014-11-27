#include "collectosap.h"

// collectOSAP: increases the player's money by $200
collectOSAP::action()
{
	occupying->money += 200;
}

// destructor
collectOSAP::~collectosap()
{
	delete occupying;
}
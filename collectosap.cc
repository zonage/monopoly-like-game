#include <iostream>
#include "collectosap.h"

// collectOSAP: increases the player's money by $200
collectOSAP::action()
{
	occupying->money += 200;
}

<<<<<<< Updated upstream
=======
// constructor
//collectOSAP::collectOSAP() {}

>>>>>>> Stashed changes
// destructor
collectOSAP::~collectosap()
{
	delete occupying;
}
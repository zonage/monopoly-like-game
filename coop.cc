#include "coop.h"

// makes player pay $150 to the bank
void CoopFee::action()
{
	occupying->money -= 150;
}

// destructor
CoopFee::~CoopFee()
{
	delete occupying;
}

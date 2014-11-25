#include "coop.h"

// makes player pay $150 to the bank
CoopFee::action()
{
	occupying->money -= 150
}

// destructor
CoopFee::~CoopFee()
{
	delete occupying;
}
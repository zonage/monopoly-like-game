#include "goosenesting.h"

// does nothing
GooseNesting::action() 
{
	cout << "You got attacked by nesting geese!" << endl;
}

// destructor
GooseNesting::~GooseNesting()
{
	delete occupying;
}
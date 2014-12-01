#include <iostream>
#include "goosenesting.h"

using namespace std;

// does nothing
void GooseNesting::action() 
{
	cout << "You got attacked by nesting geese!" << endl;
}

// destructor
GooseNesting::~GooseNesting()
{
	delete occupying;
}

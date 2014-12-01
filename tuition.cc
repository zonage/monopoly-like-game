#include <iostream>
#include "tuition.h"

using namespace std;

// action: makes players pay 10% of their worth $300
void Tuition::action()
{
	string response;
	cout << "Would you like to pay 10 percent of your worth or $300?" << endl;
	cout << "Answer: (300/10)" << endl;
	cin >> response;
	if (response == "300")
	{
		occupying->money -= 300;
	}
	else
	{
		// pays 10% of net worth
	}
}

// destructor
Tuition::~Tuition()
{
	delete occupying;
}

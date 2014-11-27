/*#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "academicbuilding.h"
#include "collectosap.h"
#include "coop.h"
#include "goosenesting.h"
#include "gototims.h"
#include "gym.h"
#include "mblock.h"
#include "needleshall.h"
#include "nonproperty.h"
#include "player.h"
#include "property.h"
#include "res.h"
#include "slc.h"
#include "square.h"
#include "timsline.h"
#include "tuition.h"
*/

#include <iostream>
#include "player.h"
#include <string>

using namespace std;

square * board[40];
Player * players[4];

int main() {
//	srand(time(NULL));
	int num;
	cout << "How many players? (1-4)" << endl;
	cin >> num;
	for(int i = 0; i < players; ++i)
	{
		string name;
		cout << "What is your name?" << endl;
		cin >> name;
		Player * p1 = new Player(name);
		players[i] = p1;
	}
	for(int i = 0; i < num; i++)
	{
		cout << players[i]->name; << endl;
	}
	for (int i =)

}

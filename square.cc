#include "square.h"
using namespace std;

Square::Square(string title, int cost, string mBlockName, int rent, int number, 
			bool purchased, bool mortgaged, Player *owner, Player *occupying, TheBoard*TB):
			number(number), title(title), cost(cost), mBlockName(mBlockName),
			rent(rent), purchased(purchased), mortgaged(mortgaged), 
			owner(owner), occupying(occupying), TB(TB)  {}

Square::~Square() {}

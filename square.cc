#include "square.h"

Square::Square(int number, string title, int cost, string mBlockName, int rent,
			bool purchased, bool mortgaged, Player *owner, Player *occupying):
			number(number), title(title), cost(cost), mBlockName(mBlockName),
			rent(rent), purchased(purchased), mortgaged(mortgaged), 
			owner(owner), occupying(occupying)  {}

Square::~Square() {}

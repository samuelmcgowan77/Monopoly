#include "BoardTile.h"

//---------- BoardTile Implementation ----------

Tiletypes BoardTile::getType()
{
	return tileType;
}

string BoardTile::getName()
{
	return name;
}

BoardTile::~BoardTile() {};
string BoardTile::getOwnerName() const {return "";};
Player *BoardTile::getOwner() const {return NULL;}
int BoardTile::getCostToBuy() const {return -1;}
void BoardTile::setOwner(Player *o) {}
int BoardTile::getRent(int roll) const {return -1;}
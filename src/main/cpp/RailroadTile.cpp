#include "RailroadTile.h"

//---------- RailroadTile Class Implementation ----------

RailroadTile::RailroadTile(string s, int buy, Tiletypes e)
{
	name = s;
	costToBuy = buy;
	tileType = e;
	owner = NULL;
	rent[0] = 25;
	rent[1] = 50;
	rent[2] = 100;
	rent[3] = 200;
}

string RailroadTile::getOwnerName() const
{
	return owner->getName();
}

Player *RailroadTile::getOwner() const
{
	return owner;
}

void RailroadTile::setOwner(Player *o)
{
	owner = o;
}

int RailroadTile::getCostToBuy() const 
{
	return costToBuy;
}

int RailroadTile::getRent() const 
{
	if (owner == NULL)
		return 0;
	return rent[owner->getNumRailroads() - 1];
} 
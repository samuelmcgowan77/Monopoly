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

string 
RailroadTile::getOwnerName() const
{
	return owner->getName();
}

shared_ptr<Player>
RailroadTile::getOwner() const
{
	return owner;
}

void 
RailroadTile::setOwner(shared_ptr<Player> o)
{
	owner = o;
}

int 
RailroadTile::getCostToBuy() const 
{
	return costToBuy;
}

int 
RailroadTile::getRent(int roll) const 
{
	if (!owner) {
		return 0;
	}

	return rent[owner->getNumRailroads() - 1];
} 
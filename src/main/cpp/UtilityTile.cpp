#include "UtilityTile.h"

//---------- UtilityTile Class Implementation ----------

UtilityTile::UtilityTile(string s, int buy, Tiletypes e)
{
	name = s;
	costToBuy = buy;
	owner = NULL;
	tileType = e;
}

string 
UtilityTile::getOwnerName() const
{
	return owner->getName();
}

shared_ptr<Player> 
UtilityTile::getOwner() const
{
	return owner;
}

void 
UtilityTile::setOwner(shared_ptr<Player> o)
{
	owner = o;
}

int 
UtilityTile::getCostToBuy() const 
{
	return costToBuy;
}

int 
UtilityTile::getRent(int roll) const 
{
	//If there isn't an owner
	if(!owner) {
		return 0;
	}
	else if(owner->getNumUtilities() == 2) {
		return roll * 10;
	}
	return roll * 4;
}
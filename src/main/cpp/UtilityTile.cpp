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
	if (owner) {
		owner->setNumUtilities(owner->getNumUtilities() - 1);
	}
	owner = o;
	owner->setNumUtilities(owner->getNumUtilities() + 1);
}

int 
UtilityTile::getCostToBuy() const 
{
	return costToBuy;
}

int 
UtilityTile::getRent(int roll) const 
{
	if(owner->getNumUtilities() == 2) {
		return roll * 10;
	}
	return roll * 4;
}
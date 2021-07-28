#include "../include/UtilityTile.h"

//---------- UtilityTile Class Implementation ----------

UtilityTile::UtilityTile(string s, int buy = 150, tiletypes e = UTILITY)
{
	name = s;
	costToBuy = buy;
	owner = NULL;
	tileType = e;
}

string UtilityTile::getOwnerName() const
{
	return owner->getName();
}

Player *UtilityTile::getOwner() const
{
	return owner;
}

void UtilityTile::setOwner(Player *o)
{
	owner = o;
}

int UtilityTile::getCostToBuy() const 
{
	return costToBuy;
}

int UtilityTile::getRent(int roll) const 
{
	if(owner == NULL)
		return 0;
	if(owner->getNumUtilities() == 2)
		return roll * 10;
	return roll * 4;
}
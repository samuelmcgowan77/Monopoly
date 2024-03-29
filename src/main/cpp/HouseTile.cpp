#include "HouseTile.h"

//---------- HouseTile Class Implementation ----------

HouseTile::HouseTile(string s, Colors c, int buy, int houseCost, int base, int oneH, int twoH, int threeH, int fourH, int hotel, int mortgageCost, Tiletypes e)
{
	name = s;
	tileType = e;
	colorType = c;
	costToBuy = buy;
	costOfHouses = houseCost;
	costOfMortgage = mortgageCost;
	owner = NULL;
	mortgaged = false;
	numHouses = 0;
	rent[0] = base;
	rent[1] = oneH;
	rent[2] = twoH;
	rent[3] = threeH;
	rent[4] = fourH;
	rent[5] = hotel;
}

string 
HouseTile::getOwnerName() const
{
	return owner->getName();
}

shared_ptr<Player>
HouseTile::getOwner() const
{
	return owner;
}

void
HouseTile::setOwner(shared_ptr<Player> o)
{
	owner = o;
}

int 
HouseTile::getCostToBuy() const 
{
	return costToBuy;
}

int 
HouseTile::getCostOfHouses() const 
{ 
	return costOfHouses;
}

int 
HouseTile::getNumHouses() const 
{
	return numHouses;
}

int 
HouseTile::getRent(int roll) const 
{
	if (owner == NULL)
		return 0;
	return rent[numHouses];
}

void 
HouseTile::buyHouse()
{
	if(owner->getMoney() >= getCostOfHouses())
	{
		owner->loseMoney(getCostOfHouses());
		numHouses++;
	}
}

Colors 
HouseTile::getColorType() const 
{
	return colorType;
}

int 
HouseTile::getMortgage() const
{
	return costOfMortgage;
}

bool 
HouseTile::isMortgaged() const
{
	return mortgaged;
}

void 
HouseTile::mortgage()
{
	mortgaged = true;
	numHouses = 0;
}

void 
HouseTile::unmortgage() {
	mortgaged = false;
}

/* HouseTile *HouseTile::operator=(BoardTile *b)
{
	return b;
} */
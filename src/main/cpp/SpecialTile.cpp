#include "SpecialTile.h"

//---------- SpecialTile Class Implementation ----------

SpecialTile::SpecialTile(Tiletypes e)
{
	tileType = e;

	switch(tileType) {
		case CHANCE:
			name = "Chance Tile";
			break;
		case CHEST:
			name = "Community Chest";
			break;
		case TAX:
			name = "Tax Tile";
			break;
		case LUXURYTAX:
			name = "Luxury Tax Tile";
			break;
		case GOTOJAIL:
			name = "Go To Jail Tile";
			break;
		case JAIL:
			name = "Jail Tile";
			break;
		case GO:
			name = "Go Tile";
			break;
		case FREE:
			name = "Free Parking Tile";
			break;
		case HOUSE:
			name = "House Tile";
			break;
		case RAILROAD:
			name = "Railroad Tile";
			break;
		case UTILITY:
			name = "Utility Tile";
			break;
	}

}

SpecialTile::~SpecialTile() {};

string SpecialTile::getOwnerName() const {return "";};
shared_ptr<Player> SpecialTile::getOwner() const {return NULL;}
int SpecialTile::getCostToBuy() const {return -1;}
void SpecialTile::setOwner(shared_ptr<Player> o) {}
int SpecialTile::getRent(int roll) const {return -1;}
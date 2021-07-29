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
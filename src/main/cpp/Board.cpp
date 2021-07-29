#include "Board.h"

//---------- Board Class Implementation ----------

Board::Board()
{
	numTiles = 0;
}

void Board::addTile(BoardTile *t)
{
	tiles[numTiles] = t;
	numTiles++;
}

BoardTile *Board::getTile(int t)
{
	return tiles[t];
}


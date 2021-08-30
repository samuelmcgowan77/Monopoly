#include "Board.h"

//---------- Board Class Implementation ----------

Board::Board()
{
	numTiles = 0;
}

void Board::addTile(shared_ptr<BoardTile> t)
{
	tiles[numTiles] = t;
	numTiles++;
}

shared_ptr<BoardTile> Board::getTile(int t)
{
	return tiles[t];
}


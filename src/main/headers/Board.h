#ifndef BOARD_H
#define BOARD_H

#include "BoardTile.h"

#endif

// ---------- Board Class ----------

class Board
{
	private:
		BoardTile *tiles[40];
		int numTiles;
	public:
		Board();
		void addTile(BoardTile *t);
		BoardTile *getTile(int t);
};
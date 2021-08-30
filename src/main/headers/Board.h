#ifndef BOARD_H
#define BOARD_H

#include "BoardTile.h"

// ---------- Board Class ----------

class Board
{
	private:
		shared_ptr<BoardTile> tiles[40];
		int numTiles;
	public:
		Board();
		void addTile(shared_ptr<BoardTile> t);
		shared_ptr<BoardTile> getTile(int t);
};

#endif
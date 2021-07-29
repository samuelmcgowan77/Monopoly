#include<queue>
#include<string>

#ifndef PLAYER_H
#define PLAYER_H

#include "Player.h"

#endif

#ifndef BOARD_H
#define BOARD_H

#include "BoardTile.h"

#endif

//---------- PlayerLine Class ----------

class PlayerLine
{
	private:
		queue<Player*> players;
	public:
		PlayerLine();
		~PlayerLine();
		int getNumPlayers();
		void addPlayer(string s, int n, BoardTile *b);
		void nextTurn();
		Player *frontLine();
};
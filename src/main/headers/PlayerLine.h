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
		// ~PlayerLine();
		int getNumPlayers() const;
		void addPlayer(string s, int num, int loc=0);
		void addPlayer(Player *p);
		void nextTurn();
		void pop();
		Player *frontLine() const;
		Player *findPlayer(int v);
		// void clone(PlayerLine *rhs);
		PlayerLine &operator=(PlayerLine *rhs);
};
#include<queue>
#include<string>
#include<memory>

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
		queue<shared_ptr<Player>> players;
	public:
		PlayerLine();
		// ~PlayerLine();
		int getNumPlayers() const;
		void addPlayer(string s, int num, int loc=0);
		void addPlayer(shared_ptr<Player> p);
		void nextTurn();
		void pop();
		shared_ptr<Player> frontLine() const;
		shared_ptr<Player> findPlayer(int v);
		// void clone(PlayerLine *rhs);
		PlayerLine &operator=(shared_ptr<PlayerLine> rhs);
};
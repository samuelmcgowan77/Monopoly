#include<queue>
#include<string>
#include "Player.h"
#include "BoardTile.h"

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
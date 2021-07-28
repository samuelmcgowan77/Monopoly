#include "../include/PlayerLine.h"

//---------- PlayerLine Class Implementation ----------

PlayerLine::PlayerLine()
{
	
}

int PlayerLine::getNumPlayers()
{
	return players.size();
}

void PlayerLine::addPlayer(string s, int n, BoardTile *b)
{
	Player *p;
	p = new Player(s,n);
	players.push(p);
}

void PlayerLine::nextTurn()
{
	Player *p = players.front();
	players.pop();
	players.push(p);
}

Player *PlayerLine::frontLine()
{
	return players.front();
}

PlayerLine::~PlayerLine()
{
	Player *p;
	for(int i = 0; i < players.size(); i++)
	{
		p = players.front();
		delete p;
		players.pop();
	}
}
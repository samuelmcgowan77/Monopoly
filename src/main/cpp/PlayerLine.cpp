#include "PlayerLine.h"

//---------- PlayerLine Class Implementation ----------

PlayerLine::PlayerLine()
{
	
}

int PlayerLine::getNumPlayers() const 
{
	return players.size();
}

void PlayerLine::addPlayer(string s, int num, int loc)
{
	Player *p;
	p = new Player(s,num,loc);
	players.push(p);
}

void PlayerLine::addPlayer(Player *p) {
	players.push(p);
}

void PlayerLine::nextTurn()
{
	Player *p = players.front();
	players.pop();
	players.push(p);
}

void PlayerLine::pop() {
	players.pop();
}

Player *PlayerLine::frontLine() const 
{
	return players.front();
}

Player *PlayerLine::findPlayer(int v) {
	PlayerLine copyLine = *this;
	Player *player = copyLine.frontLine();

	for(int i = 0; i < copyLine.getNumPlayers(); i++) {
		if(player->getPlayerNum() == v) {
			return player;
		}
		copyLine.nextTurn();
		player = copyLine.frontLine();
	}
}

// PlayerLine::~PlayerLine()
// {
// 	Player *p;
// 	for(int i = 0; i < players.size(); i++)
// 	{
// 		p = players.front();
// 		delete p;
// 		players.pop();
// 	}
// }

// void PlayerLine::clone(PlayerLine *rhs) {
// 	Player *player = rhs->frontLine();
// 	for (int i = 0; i < rhs->getNumPlayers(); i++) {
// 	    this->addPlayer(player->getName(),player->getPlayerNum());
// 		rhs->nextTurn();
// 		player = rhs->frontLine();
// 	}
// }

PlayerLine &PlayerLine::operator=(PlayerLine *rhs) {
	Player *player = rhs->frontLine();
	for (int i = 0; i < rhs->getNumPlayers(); i++) {
	    this->addPlayer(player->getName(),player->getPlayerNum(), player->getLocationNum());
		rhs->nextTurn();
		player = rhs->frontLine();
	}

	return *this;
}
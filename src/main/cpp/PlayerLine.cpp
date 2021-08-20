#include "PlayerLine.h"

//---------- PlayerLine Class Implementation ----------

PlayerLine::PlayerLine()
{
	
}

// PlayerLine::~PlayerLine() {
// 	for(int i = 0; i < getNumPlayers(); i++) {
// 		delete frontLine();
// 		players.pop();
// 	}
// }

int 
PlayerLine::getNumPlayers() const
{
	return players.size();
}

void 
PlayerLine::addPlayer(string s, int num, int loc)
{
	shared_ptr<Player> p(new Player(s,num,loc));
	players.push(p);
}

void 
PlayerLine::addPlayer(shared_ptr<Player> p) {
	players.push(p);
}

void 
PlayerLine::nextTurn()
{
	shared_ptr<Player> p(players.front());
	players.pop();
	players.push(p);
}

void 
PlayerLine::pop() {
	players.pop();
}

shared_ptr<Player> 
PlayerLine::frontLine() const 
{
	return players.front();
}

shared_ptr<Player> 
PlayerLine::findPlayer(int v) {
	PlayerLine copyLine = *this;
	shared_ptr<Player> player = copyLine.frontLine();

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

PlayerLine &PlayerLine::operator=(shared_ptr<PlayerLine> rhs) {
	shared_ptr<Player> player(rhs->frontLine());
	for (int i = 0; i < rhs->getNumPlayers(); i++) {
	    this->addPlayer(player);
		rhs->nextTurn();
		player = rhs->frontLine();
	}

	return *this;
}
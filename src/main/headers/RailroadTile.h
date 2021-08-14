#ifndef RAILROADTILE_H
#define RAILROADTILE_H

#include "BoardTile.h"

//---------- RailroadTile Class ----------
class RailroadTile : public BoardTile
{
	private:
		int costToBuy;
		shared_ptr<Player> owner;
		int rent[4];
	public:
		RailroadTile(string s, int buy = 200, Tiletypes e=RAILROAD);
		string getOwnerName() const;
		shared_ptr<Player> getOwner() const;
		void setOwner(shared_ptr<Player> o);
		int getCostToBuy() const;
		int getRent(int roll=0) const;
};

#endif
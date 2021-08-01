#ifndef BOARD_H
#define BOARD_H

#include "BoardTile.h"

#endif

//---------- RailroadTile Class ----------
class RailroadTile : public BoardTile
{
	private:
		int costToBuy;
		Player *owner;
		int rent[4];
	public:
		RailroadTile(string s, int buy = 200, Tiletypes e=RAILROAD);
		string getOwnerName() const;
		Player *getOwner() const;
		void setOwner(Player *o);
		int getCostToBuy() const;
		int getRent(int roll=0) const;
};
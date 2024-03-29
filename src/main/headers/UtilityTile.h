#ifndef UTILITYTILE_H
#define UTILITYTILE_H

#include "BoardTile.h"


//---------- UtilityTile Class Interface ----------

class UtilityTile : public BoardTile
{
	private:
		int costToBuy;
		shared_ptr<Player> owner;
	public:
		UtilityTile(string s, int buy=150, Tiletypes e=UTILITY);
		string getOwnerName() const;
		shared_ptr<Player> getOwner() const;
		void setOwner(shared_ptr<Player> o);
		int getCostToBuy() const;
		int getRent(int roll=0) const;
};
#endif
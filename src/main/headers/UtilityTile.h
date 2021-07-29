#ifndef BOARD_H
#define BOARD_H

#include "BoardTile.h"

#endif

//---------- UtilityTile Class Interface ----------

class UtilityTile : public BoardTile
{
	private:
		int costToBuy;
		Player *owner;
	public:
		UtilityTile(string s, int buy=150, Tiletypes e=UTILITY);
		string getOwnerName() const;
		Player *getOwner() const;
		void setOwner(Player *o);
		int getCostToBuy() const;
		int getCostOfHouses() const;
		int getNumHouses() const;
		int getRent() const;
		void buyHouse();
		Colors getColorType() const;
		int getRent(int roll) const;
		int getMortgage() const;
		bool isMortgaged() const;
		void mortgage();	
};
#ifndef BOARD_H
#define BOARD_H

#include "BoardTile.h"

#endif

//---------- SpecialTile Class Interface ----------

class SpecialTile : public BoardTile
{
	public:
		SpecialTile(Tiletypes e);
		~SpecialTile();
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
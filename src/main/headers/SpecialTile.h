#ifndef SPECIALTILE_H
#define SPECIALTILE_H

#include "BoardTile.h"

//---------- SpecialTile Class Interface ----------

class SpecialTile : public BoardTile
{
	public:
		SpecialTile(Tiletypes e);
		~SpecialTile();
		string getOwnerName() const;
		shared_ptr<Player> getOwner() const;
		void setOwner(shared_ptr<Player>);
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

#endif
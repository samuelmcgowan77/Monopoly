#include <string>
#ifndef BOARD_H
#define BOARD_H

#include "BoardTile.h"

#endif

using namespace std;

//---------- HouseTile Class Interface ----------

class HouseTile : public BoardTile
{
	private:
		int costToBuy;
		int costOfMortgage;
		Player *owner;
		int rent[6];
		int costOfHouses;
		int numHouses;
		Colors colorType;
		bool mortgaged;
		//HouseTile *operator=(BoardTile *b);
	public:
		HouseTile(string s, Colors c, int buy, int houseCost, int base, int oneH, int twoH, int threeH, int fourH, int hotel, int mortgageCost, Tiletypes e=HOUSE);
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
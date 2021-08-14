#ifndef HOUSETILE_H
#define HOUSETILE_H

#include <memory>
#include <string>
#include "BoardTile.h"

using namespace std;

//---------- HouseTile Class Interface ----------

class HouseTile : public BoardTile
{
	private:
		int costToBuy;
		int costOfMortgage;
		shared_ptr<Player> owner;
		int rent[6];
		int costOfHouses;
		int numHouses;
		Colors colorType;
		bool mortgaged;
		//HouseTile *operator=(BoardTile *b);
	public:
		HouseTile(string s, Colors c, int buy, int houseCost, int base, int oneH, int twoH, int threeH, int fourH, int hotel, int mortgageCost, Tiletypes e=HOUSE);
		string getOwnerName() const;
		shared_ptr<Player> getOwner() const;
		void setOwner(shared_ptr<Player>);
		int getCostToBuy() const;
		int getCostOfHouses() const;
		int getNumHouses() const;
		void buyHouse();
		Colors getColorType() const;
		int getRent(int roll=0) const;
		int getMortgage() const;
		bool isMortgaged() const;
		void mortgage();
		void unmortgage();
};

#endif
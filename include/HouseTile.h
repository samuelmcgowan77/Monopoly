#include "BoardTile.h"

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
		colors colorType;
		bool mortgaged;
		//HouseTile *operator=(BoardTile *b);
	public:
		HouseTile(std::string s, colors c, int buy, int houseCost, int base, int oneH, int twoH, int threeH, int fourH, int hotel, int mortgageCost, tiletypes e);
		string getOwnerName() const;
		Player *getOwner() const;
		void setOwner(Player *o);
		int getCostToBuy() const;
		int getCostOfHouses() const;
		int getNumHouses() const;
		int getRent() const;
		void buyHouse();
		colors getColorType() const;
		int getRent(int roll) const;
		int getMortgage() const;
		bool isMortgaged() const;
		void mortgage();
};
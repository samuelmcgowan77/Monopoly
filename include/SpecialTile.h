#include "BoardTile.h"

//---------- SpecialTile Class Interface ----------

class SpecialTile : public BoardTile
{
	public:
		SpecialTile(tiletypes e);
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
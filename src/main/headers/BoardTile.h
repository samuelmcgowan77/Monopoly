#include<string>

#ifndef PLAYER_H
#define PLAYER_H

#include "Player.h"

#endif

using namespace std;

enum Tiletypes { GO = 0, JAIL = 1, GOTOJAIL = 2, HOUSE = 3, CHEST = 4, FREE = 5, RAILROAD = 6, CHANCE = 7, TAX = 8, LUXURYTAX = 9, UTILITY = 10 };
enum Colors { PURPLE_M = 0, WHITE_M = 1, PINK_M = 2, ORANGE_M = 3, RED_M = 4, YELLOW_M = 5, GREEN_M = 6, BLUE_M = 7 };

// -------- BoardTile Class Virtual Interface ---------

class BoardTile
{
	protected:
		Tiletypes tileType;
		string name;
	public:
		virtual ~BoardTile();
		Tiletypes getType();
		string getName();
		virtual string getOwnerName() const;
		virtual Player *getOwner() const;
		virtual void setOwner(Player *o);
		virtual int getCostToBuy() const=0;
		virtual int getCostOfHouses() const=0;
		virtual int getNumHouses() const=0;
		virtual int getRent() const=0;
		virtual void buyHouse();
		virtual Colors getColorType() const;
		virtual int getRent(int roll) const=0;
		virtual int getMortgage() const;
		virtual bool isMortgaged() const;
		virtual void mortgage();
};
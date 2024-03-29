#ifndef BOARDTILE_H
#define BOARDTILE_H

#include<string>
#include<memory>
#include "Player.h"

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
		virtual shared_ptr<Player> getOwner() const;
		virtual void setOwner(shared_ptr<Player> o);
		virtual int getCostToBuy() const;
		virtual int getRent(int roll=0) const;
};
#endif
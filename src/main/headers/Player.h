#ifndef PLAYER_H
#define PLAYER_H

#include<string>

using namespace std;

// -------- Player Class Interface ----------

class Player
{
	private:
		string name;
		int playerNum;
		int money;
		int numRailroads;
		int turnsInJail;
		int locationNum;
		bool outOfJailCard;
		int numUtilities;
		//int debt;
		//Player *inDebtTo;
		bool in_game;
	public:	
		Player(string s, int p, int loc=0);
		string getName();
		int getLocationNum();
		void setLocationNum(int r);
		void move(int roll);
		void goToJail();
		int getTurnsInJail();
		void setTurnsInJail(int v);
		void getOutOfJail();
		void goToStart();
		int getMoney();
		void setMoney(int v);
		void addMoney(int v);
		void loseMoney(int v);
		bool ableToPay(int v);
		void setNumRailroads(int n);
		int getNumRailroads();
		int getNumUtilities();
		void setNumUtilities(int n);
		bool inJail();
		bool hasOutOfJailCard();
		void setOutOfJailCard(bool val);
		//int getDebt();
		//void setDebt(int d);
		//Player *getInDebtTo();
		//void setInDebtTo(Player *p);
		int getPlayerNum();
		void exitGame();
		bool inGame();
};

#endif
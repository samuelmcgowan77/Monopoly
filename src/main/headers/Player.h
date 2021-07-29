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
		bool in_jail;
		int locationNum;
		bool outOfJailCard;
		int numUtilities;
		//int debt;
		//Player *inDebtTo;
		bool in_game;
	public:	
		Player(string s, int p);
		string getName();
		int getLocationNum();
		void setLocationNum(int r);
		void move(int roll);
		void goToJail();
		void goToStart();
		int getMoney();
		void setMoney(int v);
		void setNumRailroads(int n);
		int getNumRailroads();
		int getNumUtilities();
		void setNumUtilities(int n);
		bool inJail();
		bool getOutOfJailCard();
		void setOutOfJailCard();
		void setInJail();
		//int getDebt();
		//void setDebt(int d);
		//Player *getInDebtTo();
		//void setInDebtTo(Player *p);
		int getPlayerNum();
		void gameOver();
		bool inGame();
};
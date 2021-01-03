#include<string>
#include<queue>
using namespace std;

enum types { START, JAIL, GOTOJAIL, HOUSE, CHEST, FREE, RAILROAD, CHANCE, TAX, LUXURYTAX, UTILITY };
enum colors { PURPLE, WHITE, PINK, ORANGE, RED, YELLOW, GREEN, BLUE };

//Things to consiser:
//Create a Board Class?

//***Player Class***
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

Player::Player(string s, int p)
{
	name = s;
	playerNum = p;
	money = 1500;
	numRailroads = 0;
	in_jail = false;
	locationNum = 0;
	outOfJailCard = false;
	numUtilities = 0;
	debt = 0;
	inDebtTo = NULL;
	in_game = true;
}

string Player::getName()
{
	return name;
}

int Player::getLocationNum()
{
	return locationNum;
}

void Player::move(int roll)
{
	locationNum = (locationNum + roll) % 40;
}

void Player::goToJail()
{
	locationNum = 10;
	in_jail = true;
}

void Player::goToStart()
{
	locationNum = 0;
}

int Player::getMoney()
{
	return money;
}

void Player::setMoney(int v)
{
	money = v;
}

void Player::setNumRailroads(int n)
{
	numRailroads = n;
}

int Player::getNumRailroads()
{
	return numRailroads;
}

int Player::getNumUtilities()
{
	return numUtilities;
}

void Player::setNumUtilities(int n)
{
	numUtilities = n;
}

bool Player::inJail()
{
	return in_jail;
}

bool Player::getOutOfJailCard()
{
	return outOfJailCard;
}

void Player::setInJail()
{
	in_jail = !in_jail;
}

void Player::setOutOfJailCard()
{
	outOfJailCard = !outOfJailCard;
}
/*
int Player::getDebt()
{
	return debt;
}

void Player::setDebt(int d)
{
	debt = d;
}
Player *Player::getInDebtTo()
{
	return inDebtTo;
}

void Player::setInDebtTo(Player *p)
{
	inDebtTo = p;
}
*/
int Player::getPlayerNum()
{
	return playerNum;
}

void Player::gameOver() {
	in_game = false;
}

bool Player::inGame() {
	return in_game;
}

//***BoardTile Class***
class BoardTile
{
	protected:
		types tileType;
		string name;
	public:
		types getType();
		string getName();
		virtual string getOwnerName() const;
		virtual Player *getOwner() const;
		virtual void setOwner(Player *o);
		virtual int getCostToBuy() const=0;
		virtual int getCostOfHouses() const=0;
		virtual int getNumHouses() const=0;
		virtual int getRent() const=0;
		virtual void buyHouse();
		virtual colors getColorType() const;
		virtual int getRent(int roll) const=0;
		virtual int getMortgage() const;
		virtual bool isMortgaged() const;
		virtual void mortgage();
};

types BoardTile::getType()
{
	return tileType;
}

string BoardTile::getName()
{
	return name;
}

//***Board Class***
class Board
{
	private:
		BoardTile *tiles[40];
		int numTiles;
	public:
		Board();
		void addTile(BoardTile *t);
		BoardTile *getTile(int t);
};

Board::Board()
{
	numTiles = 0;
}

void Board::addTile(BoardTile *t)
{
	tiles[numTiles] = t;
	numTiles++;
}

BoardTile *Board::getTile(int t)
{
	return tiles[t];
}

//***PlayerLine Class***
class PlayerLine
{
	private:
		queue<Player*> players;
	public:
		PlayerLine();
		~PlayerLine();
		int getNumPlayers();
		void addPlayer(string s, int n, BoardTile *b);
		void nextTurn();
		Player *frontLine();
};

PlayerLine::PlayerLine()
{
	
}

int PlayerLine::getNumPlayers()
{
	return players.size();
}

void PlayerLine::addPlayer(string s, int n, BoardTile *b)
{
	Player *p;
	p = new Player(s,n);
	players.push(p);
}

void PlayerLine::nextTurn()
{
	Player *p = players.front();
	players.pop();
	players.push(p);
}

Player *PlayerLine::frontLine()
{
	return players.front();
}

PlayerLine::~PlayerLine()
{
	Player *p;
	for(int i = 0; i < players.size(); i++)
	{
		p = players.front();
		delete p;
		players.pop();
	}
}

class SpecialTile : public BoardTile
{
	public:
		SpecialTile(types e);
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

SpecialTile::SpecialTile(types e)
{
	tileType = e;
}

//***PropertyTile Class***
/* class PropertyTile : public BoardTile
{
	protected:
		int costToBuy;
		Player *owner;
	public:
		PropertyTile(string s, types e, int b, Player *o);
		string getOwnerName();
		Player *getOwner();
		void setOwner(Player *o);
		int getCostToBuy();
};


PropertyTile::PropertyTile(string s, types e, int b, Player *o = NULL) //: BoardTile(e)
{
	name = s;
	owner = o;
	costToBuy = b;
}

string PropertyTile::getOwnerName()
{
	return owner->getName();
}

Player *PropertyTile::getOwner()
{
	return owner;
}

void PropertyTile::setOwner(Player *o)
{
	owner = o;
}

int PropertyTile::getCostToBuy()
{
	return costToBuy;
}
*/
//***HouseTile Class***
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
		HouseTile(string s, colors c, int buy, int houseCost, int base, int oneH, int twoH, int threeH, int fourH, int hotel, int mortgageCost, types e);
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

HouseTile::HouseTile(string s, colors c, int buy, int houseCost, int base, int oneH, int twoH, int threeH, int fourH, int hotel, int mortgageCost, types e = HOUSE)
{
	name = s;
	tileType = e;
	colorType = c;
	costToBuy = buy;
	costOfHouses = houseCost;
	costOfMortgage = mortgageCost;
	owner = NULL;
	mortgaged = false;
	numHouses = 0;
	rent[0] = base;
	rent[1] = oneH;
	rent[2] = twoH;
	rent[3] = threeH;
	rent[4] = fourH;
	rent[5] = hotel;
}

string HouseTile::getOwnerName() const
{
	return owner->getName();
}

Player *HouseTile::getOwner() const
{
	return owner;
}

void HouseTile::setOwner(Player *o)
{
	owner = o;
}

int HouseTile::getCostToBuy() const 
{
	return costToBuy;
}

int HouseTile::getCostOfHouses() const 
{ 
	return costOfHouses;
}

int HouseTile::getNumHouses() const 
{
	return numHouses;
}

int HouseTile::getRent() const 
{
	if (owner == NULL)
		return 0;
	return rent[numHouses];
}

void HouseTile::buyHouse()
{
	if(owner->getMoney() >= getCostOfHouses())
	{
		owner->setMoney(owner->getMoney() - getCostOfHouses());
		numHouses++;
	}
}

colors HouseTile::getColorType() const 
{
	return colorType;
}

int HouseTile::getMortgage() const
{
	return costOfMortgage;
}
bool HouseTile::isMortgaged() const
{
	return mortgaged;
}
void HouseTile::mortgage()
{
	mortgaged = !mortgaged;
	numHouses = 0;
}

/* HouseTile *HouseTile::operator=(BoardTile *b)
{
	return b;
} */

//***RailroadTile Class***
class RailroadTile : public BoardTile
{
	private:
		int costToBuy;
		Player *owner;
		int rent[4];
	public:
		RailroadTile(string s, int b, types e);
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

RailroadTile::RailroadTile(string s, int buy = 200, types e = RAILROAD)
{
	name = s;
	costToBuy = buy;
	tileType = e;
	owner = NULL;
	rent[0] = 25;
	rent[1] = 50;
	rent[2] = 100;
	rent[3] = 200;
}

string RailroadTile::getOwnerName() const
{
	return owner->getName();
}

Player *RailroadTile::getOwner() const
{
	return owner;
}

void RailroadTile::setOwner(Player *o)
{
	owner = o;
}

int RailroadTile::getCostToBuy() const 
{
	return costToBuy;
}

int RailroadTile::getRent() const 
{
	if (owner == NULL)
		return 0;
	return rent[owner->getNumRailroads() - 1];
} 

class UtilityTile : public BoardTile
{
	private:
		int costToBuy;
		Player *owner;
	public:
		UtilityTile(string s, int buy, types e);
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

UtilityTile::UtilityTile(string s, int buy = 150, types e = UTILITY)
{
	name = s;
	costToBuy = buy;
	owner = NULL;
	tileType = e;
}

string UtilityTile::getOwnerName() const
{
	return owner->getName();
}

Player *UtilityTile::getOwner() const
{
	return owner;
}

void UtilityTile::setOwner(Player *o)
{
	owner = o;
}

int UtilityTile::getCostToBuy() const 
{
	return costToBuy;
}

int UtilityTile::getRent(int roll) const 
{
	if(owner == NULL)
		return 0;
	if(owner->getNumUtilities() == 2)
		return roll * 10;
	return roll * 4;
}


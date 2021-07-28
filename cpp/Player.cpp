#include "../include/Player.h"

//---------- Player Class Implementation ----------

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
	//debt = 0;
	//inDebtTo = NULL;
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
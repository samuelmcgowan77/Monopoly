#include "Player.h"

//---------- Player Class Implementation ----------

Player::Player(string s, int p, int loc)
{
	name = s;
	playerNum = p;
	money = 1500;
	numRailroads = 0;
	turnsInJail = -1;
	locationNum = loc;
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
	turnsInJail = 0;
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

void Player::addMoney(int v) {
	money += v;
}

void Player::loseMoney(int v) {
	money -= v;
}

bool Player::ableToPay(int v) {
	return money >= v;
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
	return turnsInJail >= 0;
}

bool Player::hasOutOfJailCard()
{
	return outOfJailCard;
}

void Player::setOutOfJailCard(bool v)
{
	outOfJailCard = v;
}

int Player::getTurnsInJail() {
	return turnsInJail;
}

void Player::setTurnsInJail(int v) {
	turnsInJail = v;
}

void Player::getOutOfJail() {
	turnsInJail = -1;
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

void Player::exitGame() {
	in_game = false;
}

bool Player::inGame() {
	return in_game;
}
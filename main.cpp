#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<conio.h>
#include "Player.h"

void Draw(Board b, PlayerLine p)
{
	//x and y places of each player and 'where' represents the top(1), middle(2), and bottom(3) parts of the board
	int px[p.getNumPlayers()], py[p.getNumPlayers()], pNum[p.getNumPlayers()], where; //x is j and y is i in the for loops down below
	Player *player;
	player = p.frontLine();
	
	system("cls");
	
	//Resets copy of line to the front
	while(player->getPlayerNum() != 1)
	{
		p.nextTurn();
		player = p.frontLine();
	}
		
	
	for(int i = 0; i < p.getNumPlayers(); i++)
	{
		player = p.frontLine();
		pNum[i] = player->getPlayerNum();
		switch(player->getLocationNum())
		{
			case 0:				//Starting at the bottom of the board
				px[i] = 111 + i;
				py[i] = 3;
				where = 3;
				break;
			case 1:
				px[i]= 100 + i;
				py[i] = 3;
				where = 3;
				break;
			case 2:
				px[i] = 89 + i;
				py[i] = 3;
				where = 3;
				break;
			case 3:
				px[i] = 78 + i;
				py[i] = 3;
				where = 3;
				break;
			case 4:
				px[i] = 67 + i;
				py[i] = 3;
				where = 3;
				break;
			case 5:
				px[i] = 56 + i;
				py[i] = 3;
				where = 3;
				break;
			case 6:
				px[i] = 45 + i;
				py[i] = 3;
				where = 3;
				break;
			case 7:
				px[i] = 34 + i;
				py[i] = 3;
				where = 3;
				break;
			case 8:
				px[i] = 23 + i;
				py[i] = 3;
				where = 3;
				break;
			case 9:
				px[i] = 12 + i;
				py[i] = 3;
				where = 3;
				break;
			case 10:
				if (player->inJail())
					px[i] = 10 - i;
				else 
					px[i] = 1 + i;
				py[i] = 3;
				where = 3;
				break;
			case 11:			//Beginning of left side
				px[i] = 1 + i;
				py[i] = 43;
				where = 2;
				break;
			case 12:	
				px[i] = 1 + i;
				py[i] = 38;
				where = 2;
				break;
			case 13:
				px[i] = 1 + i;
				py[i] = 33;
				where = 2;
				break;
			case 14:
				px[i] = 1 + i;
				py[i] = 28;
				where = 2;
				break;
			case 15:
				px[i] = 1 + i;
				py[i] = 23;
				where = 2;
				break;
			case 16:
				px[i] = 1 + i;
				py[i] = 18;
				where = 2;
				break;
			case 17:
				px[i] = 1 + i;
				py[i] = 13;
				where = 2;
				break;
			case 18:
				px[i] = 1 + i;
				py[i] = 8;
				where = 2;
				break;
			case 19:
				px[i] = 1 + i;
				py[i] = 3;
				where = 2;
				break;
			case 20:				//Start of the top
				px[i] = 1 + i;
				py[i] = 3;
				where = 1;
				break;
			case 21:				
				px[i] = 12 + i;
				py[i] = 3;
				where = 1;
				break;
			case 22:				
				px[i] = 23 + i;
				py[i] = 3;
				where = 1;
				break;
			case 23:				
				px[i] = 34 + i;
				py[i] = 3;
				where = 1;
				break;
			case 24:				
				px[i] = 45 + i;
				py[i] = 3;
				where = 1;
				break;
			case 25:				
				px[i] = 56 + i;
				py[i] = 3;
				where = 1;
				break;
			case 26:				
				px[i] = 67 + i;
				py[i] = 3;
				where = 1;
				break;
			case 27:				
				px[i] = 78 + i;
				py[i] = 3;
				where = 1;
				break;
			case 28:				
				px[i] = 89 + i;
				py[i] = 3;
				where = 1;
				break;
			case 29:				
				px[i] = 100 + i;
				py[i] = 3;
				where = 1;
				break;
			case 30:				
				px[i] = 111 + i;
				py[i] = 3;
				where = 1;
				break;
			case 31:				//Start of right side
				px[i] = 111 + i;
				py[i] = 3;
				where = 2;
				break;
			case 32:
				px[i] = 111 + i;
				py[i] = 8;
				where = 2;
				break;
			case 33:
				px[i] = 111 + i;
				py[i] = 13;
				where = 2;
				break;
			case 34:
				px[i] = 111 + i;
				py[i] = 18;
				where = 2;
				break;
			case 35:
				px[i] = 111 + i;
				py[i] = 23;
				where = 2;
				break;
			case 36:
				px[i] = 111 + i;
				py[i] = 28;
				where = 2;
				break;
			case 37:
				px[i] = 111 + i;
				py[i] = 33;
				where = 2;
				break;
			case 38:
				px[i] = 111 + i;
				py[i] = 38;
				where = 2;
				break;
			case 39:
				px[i] = 111 + i;
				py[i] = 43;
				where = 2;
				break;
			default:
				break;	
		}
		p.nextTurn();
	}

	//Shows the top of the board
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 122; j++)
		{
			for (int k = 0; k < p.getNumPlayers(); k++)
			{
				if (j == px[k] && i == py[k] && where == 1)
				{
					cout << k + 1;
					j++;
				}
			}
			if (i == 0 && j == 2)
			{
				cout << "Free";
				j += 3;
			}
			else if (i == 1 && j == 2)
			{
				cout << "Parking";
				j += 6;
			}
			else if (i == 0 && j == 13)
			{
				cout << "Kentucky";
				j += 7;
			}
			else if (i == 1 && (j == 13 || j == 35 || j == 68 || j == 79))
			{
				cout << "Avenue";
				j += 5;
			}
			else if (i == 0 && j == 24)
			{
				cout << "Chance";
				j += 5;
			}
			else if (i == 0 && j == 35)
			{
				cout << "Indiana";
				j += 6;
			}
			else if (i == 0 && j == 46)
			{
				cout << "Illinois";
				j += 7;
			}
			else if (i == 0 && j == 57)
			{
				cout << "B & O";
				j += 4;
			}
			else if (i == 1 && j == 57)
			{
				cout << "Railroad";
				j += 7;
			}
			else if (i == 0 && j == 68)
			{
				cout << "Atlantic";
				j += 7;
			}
			else if (i == 0 && j == 79)
			{
				cout << "Ventnor";
				j += 6;
			}
			else if (i == 0 && j == 90)
			{
				cout << "Water";
				j += 4;
			}
			else if (i == 1 && j == 90)
			{
				cout << "Works";
				j += 4;
			}
			else if (i == 0 && j == 101)
			{
				cout << "Marvin";
				j += 5;
			}
			else if (i == 1 && j == 101)
			{
				cout << "Gardens";
				j += 6;
			}
			else if (i == 0 && j == 112)
			{
				cout << "Go to";
				j += 4;
			}
			else if (i == 1 && j == 112)
			{
				cout << "Jail";
				j += 3;
			}
			else if (j % 11 == 0)
				cout << "|";
			else 
				cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;
	//The sides of the board
	for (int i = 0; i < 44; i++)
	{
		for (int j = 0; j < 122; j++)
		{
			for (int k = 0; k < p.getNumPlayers(); k++)
			{
				if (j == px[k] && i == py[k] && where == 2)
				{
					cout << k + 1;
					j++;
				}
			}
			if ((i + 1) % 5 == 0 && i != 0 && i != 45 && ((j >= 0 && j <= 11) || j >= 110))
				cout << "-";
			else if (i == 0 && j == 2)
			{
				cout << "New York";
				j += 7;
			}
			else if ((i == 1 || i == 6 || i == 16 || i == 26) && (j == 2 || j == 112) )
			{
				cout << "Avenue";
				j += 5;
			}
			else if (i == 0 && j == 112)
			{
				cout << "Pacific";
				j += 6;
			}
			else if (i == 5 && j == 2)
			{
				cout << "Tenessee";
				j += 7;
			}
			else if (i == 5 && j == 112)
			{
				cout << "N. Carol.";
				j += 8;
			}
			else if (i == 10 && (j == 2 || j == 112))
			{
				cout << "Community";
				j += 8;
			}
			else if (i == 11 && (j == 2 || j == 112))
			{
				cout << "Chest";
				j += 4;
			}
			else if (i == 15 && j == 2)
			{
				cout << "St James";
				j += 7;
			}
			else if (i == 16 && j == 2)
			{
				cout << "Place";
				j += 4;
			}
			else if (i == 15 && j == 112)
			{
				cout << "Penn.";
				j += 4;
			}
			else if (i == 20 && j == 2)
			{
				cout << "Penn.";
				j += 4;
			}
			else if (i == 21 && j == 2)
			{
				cout << "Railroad";
				j += 7;
			}
			else if (i == 20 && j == 112)
			{
				cout << "Short";
				j += 4;
			}
			else if (i == 21 && j == 112)
			{
				cout << "Line";
				j += 3;
			}
			else if (i == 25 && j == 2)
			{
				cout << "Virginia";
				j += 7;
			}
			else if (i == 25 && j == 112)
			{
				cout << "Chance";
				j += 5;
			}
			else if (i == 30 && j == 2)
			{
				cout << "States";
				j += 5;
			}
			else if (i == 31 && j == 2)
			{
				cout << "Avenue";
				j += 5;
			}
			else if (i == 30 && j == 112)
			{
				cout << "Park";
				j += 3;
			}
			else if (i == 31 && j == 112)
			{
				cout << "Place";
				j += 4;
			}
			else if (i == 35 && j == 2)
			{
				cout << "Electric";
				j += 7;
			}
			else if (i == 36 && j == 2)
			{
				cout << "Company";
				j += 6;
			}
			else if (i == 35 && j == 112)
			{
				cout << "Luxury";
				j += 5;
			}
			else if (i == 36 && j == 112)
			{
				cout << "Tax";
				j += 2;
			}
			else if (i == 40 && j == 2)
			{
				cout << "St Char.";
				j += 7;
			}
			else if (i == 41 && j == 2)
			{
				cout << "Place";
				j += 4;
			}
			else if (i == 40 && j == 112)
			{
				cout << "Boardwalk";
				j += 8;
			}
			else if (j == 0 || j == 11 || j == 110 || j == 121)
				cout << "|";
			else 
				cout << " ";
		}
			cout << endl;
	}
	//The bottom of the board
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 122; j++)
		{
			for (int k = 0; k < p.getNumPlayers(); k++)
			{
				if (j == px[k] && i == py[k] && where == 3)
				{
					cout << k + 1;
					j++;
				}
			}	
			if (i == 0 && j == 2)
			{
				cout << "In Jail";
				j += 6;
			}
			else if (i == 0 && j == 13)
			{
				cout << "Conn.";
				j += 4;
			}
			else if (i == 1 && (j == 13 || j == 24 || j == 46 || j == 79 || j == 101))
			{
				cout << "Avenue";
				j += 5;
			}
			else if (i == 0 && j == 24)
			{
				cout << "Vermont";
				j += 6;
			}
			else if (i == 0 && j == 35)
			{
				cout << "Chance";
				j += 5;
			}
			else if (i == 0 && j == 46)
			{
				cout << "Oriental";
				j += 7;
			}
			else if (i == 0 && j == 57)
			{
				cout << "Reading";
				j += 6;
			}
			else if (i == 1 && j == 57)
			{
				cout << "Railroad";
				j += 7;
			}
			else if (i == 0 && j == 68)
			{
				cout << "Income";
				j += 5;
			}
			else if (i == 1 && j == 68)
			{
				cout << "Tax";
				j += 2;
			}
			else if (i == 0 && j == 79)
			{
				cout << "Baltic";
				j += 5;
			}
			else if (i == 0 && j == 90)
			{
				cout << "Community";
				j += 8;
			}
			else if (i == 1 && j == 90)
			{
				cout << "Chest";
				j += 4;
			}
			else if (i == 0 && j == 101)
			{
				cout << "Mediter.";
				j += 7;
			}
			else if (i == 0 && j == 112)
			{
				cout << "GO";
				j += 1;
			}
			else if (j % 11 == 0)
				cout << "|";
			else 
				cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;
}

bool gameOver(PlayerLine p)
{
	int playersInGame = 0;
	Player *player;
	
	for(int i = 0; i < p.getNumPlayers(); i++)
	{
		player = p.frontLine();
		if(player->inGame())
			playersInGame++;
		p.nextTurn();
	}
	return (playersInGame > 1);
}

void landOnHouseTile(Player *p, Board* b)
{
	bool madeDecision = false;
	int costToSell;
	BoardTile *currentPosition = b->getTile(p->getLocationNum());
	cout << "You landed on " << currentPosition->getName() << "." << endl;
		if (currentPosition->getOwner() == NULL)
		{
			cout << "No one currently owns this tile. Would you like to buy it? The cost to buy is $" << currentPosition->getCostToBuy() << ". Say buy(b) or no(n) to continue. ";
			cin >> answer;
			switch(answer)
			{
				case 'b':
					if(currentPlayer->getMoney() >= currentPosition->getCostToBuy())
					{
						currentPosition->setOwner(currentPlayer);
						currentPlayer->setMoney(currentPlayer->getMoney() - currentPosition->getCostToBuy());
						cout << "Congratulations! You are the new owner of " << currentPosition->getName() << "!" << endl;
					}
					else 
						cout << "Do not have enough money to buy " << currentPosition->getName() << ".";
					break;
			}
		}
		else if(currentPosition->getOwner() != currentPlayer && !currentPosition->isMortgaged())
		{
			if(currentPlayer->getMoney() >= currentPosition->getRent())
			{
				currentPlayer->setMoney(currentPlayer->getMoney() - currentPosition->getRent());
				currentPosition->getOwner()->setMoney(currentPosition->getOwner()->getMoney() + currentPosition->getRent());
				cout << "You had to pay rent of $" << currentPosition->getRent() << "! You now have $" << currentPlayer->getMoney() << "." << endl;
				cout << currentPosition->getOwnerName() << " now has $" << currentPosition->getOwner()->getMoney() << "." << endl;
			}
			else
			{
				cout << "Oh no! You do not have the money to pay rent for " << currentPosition->getName() << ". Are you willing to sell or mortgage one of your properties? If so, enter 's' or 'm' If not, please enter 'n'.";
				while (!madeDecision)
				{
					cin >> answerString;
					if (answerString == "n")
					{
						currentPlayer->gotoJail();
						currentPlayer->gameOver();
						cout << "You didn't have enough money to pay rent so now you're bankrupt! Game over for you!" << endl;
						getch();
						Draw(board, line);
					}
					else if (answerString == "s")
					{
						bool houseFound = false;
						while(!houseFound)
						{
							cout << "Please enter which property you want to sell: ";
							cin >> answerString;
							
							for (int i = 0; i < 40; i++)
							{
								if(board.getTile(i)->getName() == answerString && board.getTile(i)->getOwnerName() == currentPlayer->getName())
								{
									bool rightPrice = false;
									while(!rightPrice)
									{
										cout << "Please enter the agreed price: ";
										cin >> costToSell;
										if(costToSell < currentPosition->getCostToBuy() + currentPlayer->getMoney())
										{
											cout << "Cost to sell is less than rent plus what " << currentPlayer->getName() << " currently has. Must be higher." << endl;
											continue;
										}
										rightPrice = true;
									}
									board.getTile(i)->setOwner(currentPosition->getOwner());
									currentPlayer->setMoney(currentPlayer->getMoney() + costToSell - currentPosition->getCostToBuy());
									currentPosition->getOwner()->setMoney(currentPosition->getOwner()->getMoney() + currentPosition->getCostToBuy() - costToSell);
									cout << board.getTile(i)->getName() << " now belongs to " << board.getTile(i)->getOwnerName() << "." << endl;
									houseFound = true;
									break;
								}
							}
							if(!houseFound)
								cout << answerString << " could not be found. Please try again." << endl;
						}		
					}
					else if (answerString == "m")
				}	
			}
		} else 
						cout << "This tile is mortgaged so you do not have to pay any rent. " << endl;
}

//***WORK ON THIS NEXT!!!***
void drawChanceCard(Player *p, PlayerLine *l, Board *b)
{
	int cardNum = rand() % 16;
	int originalSpot = p->getLocationNum();
	BoardTile *newSpot;
	char answer;
	bool madeDecision = false;
	cout << "Your card is: " << endl;
	switch(cardNum)
	{
		case 0:
			cout << "Advance to Go (Collect $200)." << endl;
			p->goToStart();
			p->setMoney(p->getMoney() + 200);
			break;
		case 1:
			cout << "Advance to Illinois Ave--If you pass Go, collect $200." << endl;
			p->setLocationNum(24);
			if(originalSpot > 24)
			{
				cout << "You recieved $200!" << endl;
				p->setMoney(p->getMoney() + 200);
			}
			newSpot = b->getTile(24);
			if (newSpot->getOwner() == NULL)
			{
				cout << "No one currently owns this tile. Would you like to buy/mortgage it? The cost to buy is $" << newSpot->getCostToBuy() << " and the cost to mortgage is $" << newSpot->getMortgage() <<". If yes, please state which one(b/m/n). ";
				while (!madeDecision)
				{
					cin >> answer;
					switch (answer)
					{
						case 'b':
							if(p->getMoney() >= newSpot->getCostToBuy())
							{
								newSpot->setOwner(p);
								p->setMoney(p->getMoney() - newSpot->getCostToBuy());
								cout << "Congratulations! You are the new owner of " << newSpot->getName() << "!" << endl;
								madeDecision = true;
							}
							else 
								cout << "Do not have enough money to buy " << newSpot->getName() << ". Please select another option.";
							break;
						case 'm':
							if(p->getMoney() >= newSpot->getMortgage())
							{
								newSpot->setOwner(p);
								p->setMoney(p->getMoney() - newSpot->getMortgage());
								cout << "Congratulations! You have mortgaged " << newSpot->getName() << "!" << endl;
								madeDecision = true;
							}
							else 
								cout << "Do not have enough money to mortgage " << newSpot->getName() << ". Please select another option.";
								break;
						default:
							break;
					}
							
				}
			} else if(newSpot->getOwner() != p && !newSpot->isMortgaged())
				{
					if(p->getMoney() >= newSpot->getRent())
					{
						p->setMoney(p->getMoney() - newSpot->getRent());
						cout << "You had to pay rent of $" << newSpot->getRent() << "! You now have $" << p->getMoney() << "." << endl;
					}
					else
					{
						p->goToJail();
						p->setDebt(newSpot->getRent());
						p->setInDebtTo(newSpot->getOwner());
						cout << "You didn't have enough money to pay rent so you have to go to jail! You now have a debt of $" << p->getDebt() << " to "<< p->getInDebtTo() << "! Press enter to go to jail!"<< endl;
					}
				}
			break;
		case 2:
			cout << "Advance token to nearest Utility. If unowned you may buy if from the Bank. If owned, throw dice and pay owner a total ten times the amount thrown." << endl;
			break;
		case 3:
			cout << "Advance token to the nearest Railroad and pay owner twice the rental to which he/she is otherwise entitled. If Railroad is unowned, you may buy it from the Bank." << endl;
			break;
		case 4:
			cout << "Bank pays you dividend of $50." << endl;
			break;
		case 5:
			cout << "Get out of Jail Free." << endl;
			break;
		case 6:
			cout << "Go back 3 spaces." << endl;
			break;
		case 7:
			cout << "Go to Jail--go directly to jail--do not pass Go, do not collect $200." << endl;
			break;
		case 8:
			cout << "Make general repairs on all your property--for each house pay $25--for each hotel $100." << endl;
			break;
		case 9:
			cout << "Pay poor tax of $15." << endl;
			break;
		case 10:
			cout << "Take a trip to Reading Railroad--if you pass Go, collect $200." << endl;
			break;
		case 11:
			cout << "Take a walk on the Boardwalk--advance token to Boardwalk." << endl;
			break;
		case 12:
			cout << "You have been elected Chairman of the Board. Pay each player $50." << endl;
			break;
		case 13:
			cout << "Your building and loan matures--collect $150." << endl;
			break;
		case 14:
			cout << "You have won a crossword competition--collect $100." << endl;
			break;
		case 15:
			cout << "Advance to St. Charles Place--if you pass Go, collect $200." << endl;
			break;
	}
}

void drawCommunityChest()
{
	
}

using namespace std;

int main()
{
	int numPlayers, dice1, dice2;
	char answer;
	string answerString;
	PlayerLine line;
	Player *currentPlayer;
	BoardTile *currentPosition;
	//BoardTile *playerSpot;
	//PropertyTile *propertySpot;
	//HouseTile *houseSpot;
	//RailroadTile *railroadSpot;
	//UtilityTile *utilitySpot;
	int originalLocation;
	int numOfDoubles = 0;
	bool madeDecision = false;
	HouseTile *sellingTile;
	
	//Create all of the board tiles
	//These are in the order of the actual board
	SpecialTile start(START);
	HouseTile MediterraneanAvenue("Mediterranean Avenue", PURPLE, 60, 50, 2, 10, 30, 90, 160, 250, 30);
	SpecialTile chest1(CHEST);
	HouseTile BalticAvenue("Baltic Avenue", PURPLE, 60, 50, 4, 20, 60, 180, 320, 450, 30);
	SpecialTile tax1(TAX);
	RailroadTile ReadingRailroad("Reading Railroad");
	HouseTile OrientalAvenue("Oriental Avenue", WHITE, 100, 50, 6, 30, 90, 270, 400, 550, 50);
	SpecialTile chance1(CHANCE);
	HouseTile VermontAvenue("Vermont Avenue", WHITE, 100, 50, 6, 30, 90, 270, 400, 550, 50);
	HouseTile ConnecticutAvenue("Connecticut Avenue", WHITE, 120, 50, 8, 40, 100, 300, 450, 600, 60);
	SpecialTile jail(JAIL);
	HouseTile StCharlesPlace("St. Charles Place", PINK, 140, 100, 10, 50, 150, 450, 625, 750, 70);
	UtilityTile ElectricCompany("Electric Company");
	HouseTile StatesAvenue("States Avenue", PINK, 140, 100, 10, 50, 150, 450, 625, 750, 70);
	HouseTile VirginiaAvenue("Virginia Avenue", PINK, 160, 100, 12, 60, 180, 500, 700, 900, 80);
	RailroadTile PennsylvaniaRailroad("Pennsylvania Railroad");
	HouseTile StJamesPlace("St. James Place", ORANGE, 180, 100, 14, 70, 200, 550, 750, 950, 90);
	SpecialTile chest2(CHEST);
	HouseTile TenesseeAvenue("Tenessee Avenue", ORANGE, 180, 100, 14, 70, 200, 550, 750, 950, 90);
	HouseTile NewYorkAvenue("New York Avenue", ORANGE, 200, 100, 16, 80, 220, 600, 800, 1000, 100);
	SpecialTile FreeParking(FREE);
	HouseTile KentuckyAvenue("Kentucky Avenue", RED, 220, 150, 18, 90, 250, 700, 875, 1050, 110);
	SpecialTile chance2(CHANCE);
	HouseTile IndianaAvenue("Indiana Avenue", RED, 220, 150, 18, 90, 250, 700, 875, 1050, 110);
	HouseTile IllinoisAvenue("Illinois Avenue", RED, 240, 150, 20, 100, 300, 750, 925, 1100, 120);
	RailroadTile BandORailroad("B&O Railroad");
	HouseTile AtlanticAvenue("Atlantic Avenue", YELLOW, 260, 150, 22, 110, 330, 800, 975, 1150, 130);
	HouseTile VentnorAvenue("Ventnor Avenue", YELLOW, 260, 150, 22, 110, 330, 800, 975, 1150, 130);
	UtilityTile WaterWorks ("Water Works");
	HouseTile MarvinGardens("Marvin Gardens", YELLOW, 280, 150, 24, 120, 360, 850, 1025, 1200, 140);
	SpecialTile GoToJail(GOTOJAIL);
	HouseTile PacificAvenue("Pacific Avenue", GREEN, 300, 200, 26, 130, 390, 900, 1100, 1275, 150);
	HouseTile NorthCarolinaAvenue("North Carolina Avenue", GREEN, 300, 200, 26, 130, 390, 900, 1100, 1275, 150);
	SpecialTile chest3(CHEST);
	HouseTile PennsylvaniaAvenue("Pennsylvania Avenue", GREEN, 320, 200, 28, 150, 450, 1000, 1200, 1400, 160);
	RailroadTile ShortLineRailroad("Short Line");
	SpecialTile chance3(CHANCE);
	HouseTile ParkPlace("Park Place", BLUE, 350, 200, 35, 175, 500, 1100, 1300, 1500, 175);
	SpecialTile luxuryTax(LUXURYTAX);
	HouseTile Boardwalk("Boardwalk", BLUE, 400, 200, 50, 200, 600, 1400, 1700, 2000, 200);
	
	Board board;
	board.addTile(&start);
	board.addTile(&MediterraneanAvenue);
	board.addTile(&chest1);
	board.addTile(&BalticAvenue);
	board.addTile(&tax1);
	board.addTile(&ReadingRailroad);
	board.addTile(&OrientalAvenue);
	board.addTile(&chance1);
	board.addTile(&VermontAvenue);
	board.addTile(&ConnecticutAvenue);
	board.addTile(&jail);
	board.addTile(&StCharlesPlace);
	board.addTile(&ElectricCompany);
	board.addTile(&StatesAvenue);
	board.addTile(&VirginiaAvenue);
	board.addTile(&PennsylvaniaAvenue);
	board.addTile(&StJamesPlace);
	board.addTile(&chest2);
	board.addTile(&TenesseeAvenue);
	board.addTile(&NewYorkAvenue);
	board.addTile(&FreeParking);
	board.addTile(&KentuckyAvenue);
	board.addTile(&chance2);
	board.addTile(&IndianaAvenue);
	board.addTile(&IllinoisAvenue);
	board.addTile(&BandORailroad);
	board.addTile(&AtlanticAvenue);
	board.addTile(&VentnorAvenue);
	board.addTile(&WaterWorks);
	board.addTile(&MarvinGardens);
	board.addTile(&GoToJail);
	board.addTile(&PacificAvenue);
	board.addTile(&NorthCarolinaAvenue);
	board.addTile(&chest3);
	board.addTile(&PennsylvaniaAvenue);
	board.addTile(&ShortLineRailroad);
	board.addTile(&chance3);
	board.addTile(&ParkPlace);
	board.addTile(&luxuryTax);
	board.addTile(&Boardwalk);
	
	cout << "Welcome to Monopoly! Enter number of players: ";
	cin >> numPlayers;
	cout << endl;
	
	string name[numPlayers];
	
	cout << "Enter the name of each player." << endl;
	for (int i = 0; i < numPlayers; i++)
	{
		cout << "Player " << i + 1 << ": ";
		cin >> name[i];
	}
	
	for(int i = 0; i < numPlayers; i++)
		line.addPlayer(name[i], i + 1, &start);
		
	while(!gameOver(line))
	{
		Draw(board, line);
		currentPlayer = line.frontLine();
		
		if (!currentPlayer->inJail())
		{
			originalLocation = currentPlayer->getLocationNum();
			cout << currentPlayer->getName() << "'s Turn. Press enter to roll!" << endl;
			getch();
			dice1 = rand() % 6 + 1;
			dice2 = rand() % 6 + 1;
			currentPlayer->move(dice1 + dice2);
			Draw(board, line);
			cout << "Dice 1: " << dice1 << endl;
			cout << "Dice 2: " << dice2 << endl;
			cout << currentPlayer->getName() << "'s Money: $" << currentPlayer->getMoney() << endl;
			cout << currentPlayer->getName() << "'s Owned Tiles: ";
			for (int i = 0; i < 40; i++)
			{
				if (board.getTile(i)->getOwnerName() == currentPlayer->getName())
					cout << board.getTile(i)->getName() << "   ";
			}
			cout << endl;
			if(originalLocation > currentPlayer->getLocationNum())
			{
				currentPlayer->setMoney(currentPlayer->getMoney() + 200);
				cout << "Congratulations! You went all the way around and received $200! You now have $" << currentPlayer->getMoney() << "." << endl;
			}
			currentPosition = board.getTile(currentPlayer->getLocationNum());
			getch();
			switch(currentPosition->getType())
			{
				case START:
					cout << "You landed on the Go tile!" << endl; 
					break;
				case JAIL:
					cout << "Just passing through at the Jail tile!" << endl;
					break;
				case GOTOJAIL:
					cout << "Oh no! You landed on the Go to Jail tile! Press enter to go to jail!" << endl;
					currentPlayer->goToJail();
					getch();
					Draw(board, line);
					break;
				case HOUSE: //Change it to where if you can't pay rent then you either sell a property to the owner or go bankrupt(game over)
					cout << "You landed on " << currentPosition->getName() << "." << endl;
					if (currentPosition->getOwner() == NULL)
					{
						cout << "No one currently owns this tile. Would you like to buy/mortgage it? The cost to buy is $" << currentPosition->getCostToBuy() << " and the cost to mortgage is $" << currentPosition->getMortgage() <<". If yes, please state which one(b/m) or no(n) to continue. ";
						while (!madeDecision)
						{
							cin >> answer;
							switch (answer)
							{
								case 'b':
									if(currentPlayer->getMoney() >= currentPosition->getCostToBuy())
									{
										currentPosition->setOwner(currentPlayer);
										currentPlayer->setMoney(currentPlayer->getMoney() - currentPosition->getCostToBuy());
										cout << "Congratulations! You are the new owner of " << currentPosition->getName() << "!" << endl;
										madeDecision = true;
									}
									else 
										cout << "Do not have enough money to buy " << currentPosition->getName() << ". Please select another option.";
									break;
								case 'm':
									if(currentPlayer->getMoney() >= currentPosition->getMortgage())
									{
										currentPosition->setOwner(currentPlayer);
										currentPlayer->setMoney(currentPlayer->getMoney() - currentPosition->getMortgage());
										currentPosition->mortgage();
										cout << "Congratulations! You have mortgaged " << currentPosition->getName() << "!" << endl;
										madeDecision = true;
									}
									else 
										cout << "Do not have enough money to mortgage " << currentPosition->getName() << ". Please select another option.";
									break;
								case 'n':
									madeDecision = true;
									break;
							}
						}
					madeDecision = false;
					} else if(currentPosition->getOwner() != currentPlayer && !currentPosition->isMortgaged())
					{
						if(currentPlayer->getMoney() >= currentPosition->getRent())
						{
						currentPlayer->setMoney(currentPlayer->getMoney() - currentPosition->getRent());
						cout << "You had to pay rent of $" << currentPosition->getRent() << "! You now have $" << currentPlayer->getMoney() << "." << endl;
						}
						else
						{
							cout << "Oh no! You do not have the money to pay rent for " << currentPosition->getName() << ". Are you willing to give up a certain property? If so, please enter the property name. If not, please enter 'n'.";
							while (!madeDecision)
							{
								cin >> answerString;
								if (answerString == "n")
								{
									currentPlayer->goToJail();
									currentPosition->getOwner()->setMoney(currentPosition->getOwner()->getMoney() + currentPlayer->getMoney());
									currentPlayer->setDebt(currentPosition->getRent() - currentPlayer->getMoney());
									currentPlayer->setMoney(0);
									currentPlayer->setInDebtTo(currentPosition->getOwner());
									cout << "You didn't have enough money to pay rent so you have to go to jail! You now have a debt of $" << currentPlayer->getDebt() << " to "<< currentPlayer->getInDebtTo() << "! Press enter to go to jail!"<< endl;
									getch();
									Draw(board, line);
								}
								else
								{
									for (int i = 0; i < 40; i++)
									{
										if(board.getTile(i)->getName() == answerString && board.getTile(i)->getOwnerName() == currentPlayer->getName())
										{
											board.getTile(i)->setOwner(currentPosition->getOwner());
											cout << board.getTile(i)->getName() << " now belongs to " << board.getTile(i)->getOwnerName() << "." << endl;
										}
									}		
								}
							}	
						}
					} else 
						cout << "This tile is mortgaged so you do not have to pay any rent. " << endl;
				case CHEST:
					cout << "You landed on the Community Chest! Press enter to draw!" << endl;
					getch();
					drawCommunityChest();
				case FREE:
					cout << "You landed on free parking!" << endl;
					break;
				case RAILROAD:
					cout << "You landed on " << currentPosition->getName() << "!" << endl;
					if(currentPosition->getOwner() == NULL)
					{
						
					}
				case CHANCE:
					cout << "You landed on a Chance tile! Press enter to draw a chance card!" << endl;
					getch();
					drawChanceCard();
					cout << "Press enter to continue!" << endl;
					getch();
					Draw(board, line);
					break;
				case TAX:
				case LUXURYTAX:
				case UTILITY:
			}
		}
	}	
		
	
	return 0;
}

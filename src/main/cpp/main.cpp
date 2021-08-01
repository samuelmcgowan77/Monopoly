//#include<iostream>
#include<string>
#include<queue>
#include "Monopoly.h"

/*
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
*/

//***WORK ON THIS NEXT!!!***
/* void drawChanceCard(Player *p, PlayerLine *l, Board *b)
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
} */

using namespace std;

int main()
{
	int numPlayers, dice1, dice2;
	char answer;
	string answerString;
	PlayerLine line;
	Player *currentPlayer;
	BoardTile *currentTile;
	int originalLocation;
	int numOfDoubles = 0;
	bool madeDecision = false;
	bool initiallyInJail = false;
	HouseTile *sellingTile;
	
	//Create all of the board tiles
	//These are in the order of the actual board
	SpecialTile start(GO);
	HouseTile MediterraneanAvenue("Mediterranean Avenue", PURPLE_M, 60, 50, 2, 10, 30, 90, 160, 250, 30, HOUSE);
	SpecialTile chest1(CHEST);
	HouseTile BalticAvenue("Baltic Avenue", PURPLE_M, 60, 50, 4, 20, 60, 180, 320, 450, 30);
	SpecialTile tax1(TAX);
	RailroadTile ReadingRailroad("Reading Railroad");
	HouseTile OrientalAvenue("Oriental Avenue", WHITE_M, 100, 50, 6, 30, 90, 270, 400, 550, 50);
	SpecialTile chance1(CHANCE);
	HouseTile VermontAvenue("Vermont Avenue", WHITE_M, 100, 50, 6, 30, 90, 270, 400, 550, 50);
	HouseTile ConnecticutAvenue("Connecticut Avenue", WHITE_M, 120, 50, 8, 40, 100, 300, 450, 600, 60);
	SpecialTile jail(JAIL);
	HouseTile StCharlesPlace("St. Charles Place", PINK_M, 140, 100, 10, 50, 150, 450, 625, 750, 70);
	UtilityTile ElectricCompany("Electric Company");
	HouseTile StatesAvenue("States Avenue", PINK_M, 140, 100, 10, 50, 150, 450, 625, 750, 70);
	HouseTile VirginiaAvenue("Virginia Avenue", PINK_M, 160, 100, 12, 60, 180, 500, 700, 900, 80);
	RailroadTile PennsylvaniaRailroad("Pennsylvania Railroad");
	HouseTile StJamesPlace("St. James Place", ORANGE_M, 180, 100, 14, 70, 200, 550, 750, 950, 90);
	SpecialTile chest2(CHEST);
	HouseTile TenesseeAvenue("Tenessee Avenue", ORANGE_M, 180, 100, 14, 70, 200, 550, 750, 950, 90);
	HouseTile NewYorkAvenue("New York Avenue", ORANGE_M, 200, 100, 16, 80, 220, 600, 800, 1000, 100);
	SpecialTile FreeParking(FREE);
	HouseTile KentuckyAvenue("Kentucky Avenue", RED_M, 220, 150, 18, 90, 250, 700, 875, 1050, 110);
	SpecialTile chance2(CHANCE);
	HouseTile IndianaAvenue("Indiana Avenue", RED_M, 220, 150, 18, 90, 250, 700, 875, 1050, 110);
	HouseTile IllinoisAvenue("Illinois Avenue", RED_M, 240, 150, 20, 100, 300, 750, 925, 1100, 120);
	RailroadTile BandORailroad("B&O Railroad");
	HouseTile AtlanticAvenue("Atlantic Avenue", YELLOW_M, 260, 150, 22, 110, 330, 800, 975, 1150, 130);
	HouseTile VentnorAvenue("Ventnor Avenue", YELLOW_M, 260, 150, 22, 110, 330, 800, 975, 1150, 130);
	UtilityTile WaterWorks ("Water Works");
	HouseTile MarvinGardens("Marvin Gardens", YELLOW_M, 280, 150, 24, 120, 360, 850, 1025, 1200, 140);
	SpecialTile GoToJail(GOTOJAIL);
	HouseTile PacificAvenue("Pacific Avenue", GREEN_M, 300, 200, 26, 130, 390, 900, 1100, 1275, 150);
	HouseTile NorthCarolinaAvenue("North Carolina Avenue", GREEN_M, 300, 200, 26, 130, 390, 900, 1100, 1275, 150);
	SpecialTile chest3(CHEST);
	HouseTile PennsylvaniaAvenue("Pennsylvania Avenue", GREEN_M, 320, 200, 28, 150, 450, 1000, 1200, 1400, 160);
	RailroadTile ShortLineRailroad("Short Line");
	SpecialTile chance3(CHANCE);
	HouseTile ParkPlace("Park Place", BLUE_M, 350, 200, 35, 175, 500, 1100, 1300, 1500, 175);
	SpecialTile luxuryTax(LUXURYTAX);
	HouseTile Boardwalk("Boardwalk", BLUE_M, 400, 200, 50, 200, 600, 1400, 1700, 2000, 200);
	
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
	board.addTile(&PennsylvaniaRailroad);
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

	//HouseTile ht = *(HouseTile *)board.getTile(1);
	
	cout << "Welcome to Monopoly! Enter number of players: ";
	cin >> numPlayers;
	cout << endl;
	
	string name[numPlayers];
	
	cout << "Enter the name of each player." << endl;
	for (int i = 0; i < numPlayers; i++)
	{
		cout << "Player " << i + 1 << ": ";
		cin >> name[i];
		getchar(); //First getchar in the game picks up enter from this cin
	}
	
	for(int i = 0; i < numPlayers; i++)
		line.addPlayer(name[i], i + 1);
	
	Monopoly game(&board, &line);
	
	Player *p = line.frontLine();
	
	// while(!game.gameOver()) {
	// 	game.drawBoard();
	// 	for(int i = 0; i < line.getNumPlayers(); i++) {
	// 		cout << p->getLocationNum() << " " << p->getName() << endl;
	// 		p->move(1);
	// 		line.nextTurn();
	// 		p = line.frontLine();		
	// 	}
	// 	getchar();
		
	// }


	while(!game.gameOver())
	{
		game.drawBoard();

		currentPlayer = game.getCurrentPlayer();
		originalLocation = currentPlayer->getLocationNum();

		game.print(currentPlayer->getName() + "'s turn! Press any key to roll!");
		
		if(currentPlayer->inJail()) {
			game.attemptOutOfJail();
			if(currentPlayer->inJail()) {
				line.nextTurn();
				continue;
			}
			currentPlayer->move(game.getRoll());
		}
		else {
			currentPlayer->move(game.roll());
			// currentPlayer->move(1);
		}

		currentTile = game.getCurrentTile();

    	game.print("You rolled a " + to_string(game.getDie(1)) + " and a " + to_string(game.getDie(2)) + "!", true, false);
		game.print("Landed on " + currentTile->getName() + "!");

		if(currentPlayer->getLocationNum() < originalLocation) {
			game.print("Since you passed GO you received $200!", true, false);
			currentPlayer->addMoney(200);
		}
		
		switch(currentTile->getType())
		{
			case GO: 
				break;
			case JAIL:
				cout << "Just passing through!" << endl;
				break;
			case GOTOJAIL:
				cout << "You're going to jail!" << endl;
				// currentPlayer->goToJail();
				break;
			case HOUSE: //Change it to where if you can't pay rent then you either sell a property to the owner or go bankrupt(game over)
				// game.landOnHouseTile();
				break;
			case CHEST:
				break;
			case FREE:
				break;
			case RAILROAD:
				break;
			case CHANCE:
				break;
			case TAX:
				game.print("You have to pay $75!", true, false);
				break;
			case LUXURYTAX:
				game.landOnLuxuryTaxTile();
				break;
			case UTILITY:
				break;
		}
		if(game.rollDoubles() && !initiallyInJail) {
			game.print("Since you rolled doubles you get to go again!");
			continue;
		}

		line.nextTurn();
	}	

	// 	originalLocation = currentPlayer->getLocationNum();
	// 	cout << currentPlayer->getName() << "'s Turn. Press enter to roll!" << endl;
	// 	getch();
	// 	dice1 = rand() % 6 + 1;
	// 	dice2 = rand() % 6 + 1;
	// 	currentPlayer->move(dice1 + dice2);
	// 	Draw(board, line);
	// 	cout << "Dice 1: " << dice1 << endl;
	// 	cout << "Dice 2: " << dice2 << endl;
	// 	cout << currentPlayer->getName() << "'s Money: $" << currentPlayer->getMoney() << endl;
	// 	cout << currentPlayer->getName() << "'s Owned Tiles: ";
	// 	for (int i = 0; i < 40; i++)
	// 	{
	// 		if (board.getTile(i)->getOwnerName() == currentPlayer->getName())
	// 			cout << board.getTile(i)->getName() << "   ";
	// 	}
	// 	cout << endl;
	// 	if(originalLocation > currentPlayer->getLocationNum())
	// 	{
	// 		currentPlayer->setMoney(currentPlayer->getMoney() + 200);
	// 		cout << "Congratulations! You went all the way around and received $200! You now have $" << currentPlayer->getMoney() << "." << endl;
	// 	}
	// 	currentPosition = board.getTile(currentPlayer->getLocationNum());
	// 	getch();
				
	
	return 0;
}

//#include<iostream>
#include<memory>
#include<string>
#include<queue>
#include "Monopoly.h"

using namespace std;

int main()
{
	int numPlayers;
	shared_ptr<PlayerLine> line(new PlayerLine());
	shared_ptr<Player> currentPlayer;
	shared_ptr<BoardTile> currentTile;
	int originalLocation;
	bool initiallyInJail = false;
	
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
	board.addTile(shared_ptr<BoardTile>(&start));
	board.addTile(shared_ptr<BoardTile>(&MediterraneanAvenue));
	board.addTile(shared_ptr<BoardTile>(&chest1));
	board.addTile(shared_ptr<BoardTile>(&BalticAvenue));
	board.addTile(shared_ptr<BoardTile>(&tax1));
	board.addTile(shared_ptr<BoardTile>(&ReadingRailroad));
	board.addTile(shared_ptr<BoardTile>(&OrientalAvenue));
	board.addTile(shared_ptr<BoardTile>(&chance1));
	board.addTile(shared_ptr<BoardTile>(&VermontAvenue));
	board.addTile(shared_ptr<BoardTile>(&ConnecticutAvenue));
	board.addTile(shared_ptr<BoardTile>(&jail));
	board.addTile(shared_ptr<BoardTile>(&StCharlesPlace));
	board.addTile(shared_ptr<BoardTile>(&ElectricCompany));
	board.addTile(shared_ptr<BoardTile>(&StatesAvenue));
	board.addTile(shared_ptr<BoardTile>(&VirginiaAvenue));
	board.addTile(shared_ptr<BoardTile>(&PennsylvaniaRailroad));
	board.addTile(shared_ptr<BoardTile>(&StJamesPlace));
	board.addTile(shared_ptr<BoardTile>(&chest2));
	board.addTile(shared_ptr<BoardTile>(&TenesseeAvenue));
	board.addTile(shared_ptr<BoardTile>(&NewYorkAvenue));
	board.addTile(shared_ptr<BoardTile>(&FreeParking));
	board.addTile(shared_ptr<BoardTile>(&KentuckyAvenue));
	board.addTile(shared_ptr<BoardTile>(&chance2));
	board.addTile(shared_ptr<BoardTile>(&IndianaAvenue));
	board.addTile(shared_ptr<BoardTile>(&IllinoisAvenue));
	board.addTile(shared_ptr<BoardTile>(&BandORailroad));
	board.addTile(shared_ptr<BoardTile>(&AtlanticAvenue));
	board.addTile(shared_ptr<BoardTile>(&VentnorAvenue));
	board.addTile(shared_ptr<BoardTile>(&WaterWorks));
	board.addTile(shared_ptr<BoardTile>(&MarvinGardens));
	board.addTile(shared_ptr<BoardTile>(&GoToJail));
	board.addTile(shared_ptr<BoardTile>(&PacificAvenue));
	board.addTile(shared_ptr<BoardTile>(&NorthCarolinaAvenue));
	board.addTile(shared_ptr<BoardTile>(&chest3));
	board.addTile(shared_ptr<BoardTile>(&PennsylvaniaAvenue));
	board.addTile(shared_ptr<BoardTile>(&ShortLineRailroad));
	board.addTile(shared_ptr<BoardTile>(&chance3));
	board.addTile(shared_ptr<BoardTile>(&ParkPlace));
	board.addTile(shared_ptr<BoardTile>(&luxuryTax));
	board.addTile(shared_ptr<BoardTile>(&Boardwalk));
	
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
		line->addPlayer(name[i], i + 1);
	
	Monopoly game(shared_ptr<Board>(&board), line);
	
	// shared_ptr<Player> p(line->frontLine());
	// 
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
		//originalLocation = currentPlayer->getLocationNum();
		initiallyInJail = currentPlayer->inJail();
		
		if(!currentPlayer->inJail()) {
			game.print(currentPlayer->getName() + "'s turn! Press any key to roll!");
			game.moveCurrentPlayer(game.roll());
			// currentPlayer->move(1);	
			if (game.rollDoubles()) {
				currentPlayer->incNumDoubles();
				if (currentPlayer->getNumDoubles() >= 3) {
					game.print("This is your third double in a row! You're going to jail");
					game.sendPlayerToJail(currentPlayer);
					line->nextTurn();
					continue;
				}
			}
		}
		else {
			game.print(currentPlayer->getName() + "'s turn!");
			game.attemptOutOfJail();
			if(currentPlayer->inJail()) {
				line->nextTurn();
				continue;
			}
			game.moveCurrentPlayer(game.getRoll());
		}

		currentTile = game.getCurrentTile();

		game.print("Landed on " + currentTile->getName() + "!");
		
		switch(currentTile->getType())
		{
			case GO: 
				break;
			case JAIL:
				game.print("Just passing through!");
				break;
			case GOTOJAIL:
				cout << "You're going to jail!" << endl;
				currentPlayer->goToJail();
				break;
			case HOUSE: //Change it to where if you can't pay rent then you either sell a property to the owner or go bankrupt(game over)
				game.landOnHouseTile();
				break;
			case CHEST:
				break;
			case FREE:
				break;
			case RAILROAD:
				game.landOnRailroadTile();
				break;
			case CHANCE:
				game.drawChanceCard();
				break;
			case TAX:
				game.print("You have to pay $75!", true, false);
				currentPlayer->loseMoney(75);
				break;
			case LUXURYTAX:
				game.landOnLuxuryTaxTile();
				break;
			case UTILITY:
				game.landOnUtilityTile();
				break;
		}
		if(game.rollDoubles() && !initiallyInJail) {
			game.print("Since you rolled doubles you get to go again!");
			continue;
		}

		line->nextTurn();
	}	

	// 	originalLocation = currentPlayer->getLocationNum();
	// 	cout << currentPlayer->getName() << "'s Turn. Press enter to roll!" << endl;
	// 	getch();
	// 	dice1 = rand() % 6 + 1;
	// 	dice2 = rand() % 6 + 1;
	// 	currentPlayer->move(dice1 + dice2);
	// 	Draw(board, line);
	// 	 << "Dice 1: " << dice1 << endl;
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

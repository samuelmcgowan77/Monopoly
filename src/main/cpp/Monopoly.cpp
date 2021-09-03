#include "Monopoly.h"

Monopoly::Monopoly(shared_ptr<Board> b, shared_ptr<PlayerLine> l) {
    board = b;
    line = l;
}

bool 
Monopoly::gameOver() {
	int playersInGame = 0;
	shared_ptr<Player> player;
	
	for(int i = 0; i < line->getNumPlayers(); i++)
	{
		player = getCurrentPlayer();
		if(player->inGame())
			playersInGame++;
		line->nextTurn();
	}
	return (playersInGame <= 1);
}

int 
Monopoly::roll() {
    dice1 = 1; //rand() % 6 + 1;
	dice2 = 1; //rand() % 6 + 1;

	print("You rolled a " + to_string(dice1) + " and a " + to_string(dice2) + "!", true, false);
    
    return dice1 + dice2;
}

bool 
Monopoly::rollDoubles() {
    return dice1 == dice2;
}

int 
Monopoly::getRoll() {
    return dice1 + dice2;
}

int 
Monopoly::getDie(int v) {
	return v == 1 ? dice1 : dice2;
}

void 
Monopoly::attemptOutOfJail() {
    
    shared_ptr<Player> player(getCurrentPlayer());
    int turnsInJail = player->getTurnsInJail();

	print("You have been in jail for " + to_string(turnsInJail) + " turns.", true, false);
    if(turnsInJail < 3) {
        if(player->getMoney() >= 50) {
            
            string ans;
            bool answered = false;

            while (!answered) {
				print("Would you like to get out of jail for $50? (y/n)", false, false);
                cin >> ans;
				getchar();

                if(ans == "y") {
                    player->loseMoney(50);
                    player->getOutOfJail();
					print("Press any key to roll!");
                    roll();
                    answered = true;
                }
                else if (ans == "n") {
                    rollDiceInJail(player);
                    answered = true;
                }
                else {
					print("Please enter a valid answer.", false, true);
                }
            }
        }
    }
    else {
        rollDiceInJail(player);
    }
}

void Monopoly::rollDiceInJail(shared_ptr<Player> player) {
	print("You have to roll the dice in jail! Press any key to roll!", true, false);

    int r = roll();
    if(rollDoubles()) {
		print("You got doubles! You will now move out of jail from your roll!", true, false);
        player->getOutOfJail();
    }
    else {
        if(player->getTurnsInJail() >= 3) {
            if(!player->ableToPay(50)) {
				print("You could not pay the $50 bail! GAME OVER FOR YOU!");
                player->exitGame();
            }
            else {;
                player->loseMoney(50);
				print("Had to pay $50 bail. Now have $" + to_string(player->getMoney()) + ".", true, false);
            }
        }
        else {
			print("Still in jail. Turn has ended.");
        }
    }
}

shared_ptr<Player> 
Monopoly::getCurrentPlayer() {
    return line->frontLine();
}

shared_ptr<BoardTile>
Monopoly::getCurrentTile() {
    int loc = getCurrentPlayer()->getLocationNum();
    return board->getTile(loc);
}

/* Put the landOn functions into one? */
void
Monopoly::landOnRailroadTile(int multiply) {
	shared_ptr<RailroadTile> railroadTile(static_pointer_cast<RailroadTile>(getCurrentTile()));
    shared_ptr<Player> owner(railroadTile->getOwner());
    shared_ptr<Player> player(getCurrentPlayer());

    if(!owner) {
        askToBuyProperty(player, railroadTile);
    } else {
		payRentTo(player, owner, railroadTile, multiply);
    }
}

void
Monopoly::landOnUtilityTile() {
	shared_ptr<UtilityTile> utilityTile(static_pointer_cast<UtilityTile>(getCurrentTile()));
	shared_ptr<Player> owner(utilityTile->getOwner());
    shared_ptr<Player> player(getCurrentPlayer());

	if(!owner) {
        askToBuyProperty(player, utilityTile);
    } else {
		payRentTo(player, owner, utilityTile, 1, getRoll());
    }
}

void 
Monopoly::landOnHouseTile() {
    shared_ptr<HouseTile> houseTile(static_pointer_cast<HouseTile>(getCurrentTile()));
    shared_ptr<Player> owner(houseTile->getOwner());
    shared_ptr<Player> player(getCurrentPlayer());

    if(!owner) {
        askToBuyProperty(player, houseTile);
    } else if(owner->getPlayerNum() != player->getPlayerNum() && !houseTile->isMortgaged()) {
        payRentTo(player, owner, houseTile);
    } else if (houseTile->isMortgaged()) {
		print("Since the house is currently mortgaged, you don't have to pay rent!", true, false);
	}
}

void 
Monopoly::askToBuyProperty(shared_ptr<Player> player, shared_ptr<BoardTile> propertyTile) {
	if(propertyTile->getCostToBuy() > player->getMoney()) {
			print("You do not have enough funds to buy.", true, false);
            return;
        }

	bool answered = false;
	string ans;
	while(!answered) {
			print("Would you like to buy this property? The cost is $" + to_string(propertyTile->getCostToBuy()) + ". (y/n)", false, false);
            cin >> ans;
			getchar();
            if(ans == "y") {
                player->loseMoney(propertyTile->getCostToBuy());
                propertyTile->setOwner(player);
				print("Congratulations! You bought " + propertyTile->getName() + "!");
                answered = true;
            }
            else if(ans == "n") {
				if(propertyTile->getType() == HOUSE) {
					auctionHouse(static_pointer_cast<HouseTile>(propertyTile));
				}
                answered = true;
            }
            else {
				print("Please enter a valid answer.", false, true);
            }
        }
}

void 
Monopoly::auctionHouse(shared_ptr<HouseTile> house) {
    PlayerLine copyLine = *line;    
    int bid[copyLine.getNumPlayers()];
    int givingBid = 0;
	shared_ptr<Player> winningPlayer;
    int highestPlayer = 1;
	copyLine.pop();
	shared_ptr<Player> player(copyLine.frontLine());

    for (int i = 0; i < copyLine.getNumPlayers(); i++) {
        bid[i] = 0;
    }
    
    while(copyLine.getNumPlayers() > 0) {		
		print("Number of bidders remaining: " + copyLine.getNumPlayers(), false, false);

        if(bid[highestPlayer - 1] > 0) {
			winningPlayer = copyLine.findPlayer(highestPlayer);
			print("Highest Bid: $" + to_string(bid[highestPlayer - 1]) + " from " + winningPlayer->getName() + "!", false, false);
        }

		print( player->getName() + ", what would you like to bid? Enter -1 to not bid anymore.", false, false);
        cin >> givingBid;
		getchar();
        if(givingBid > player->getMoney()) {
			print("Bid is higher than what you currently have. Please bid lower.", true, false);
        }
        else if(givingBid < 0) {
            copyLine.pop();
			player = copyLine.frontLine();
			continue;
        }
		else if(givingBid <= bid[highestPlayer - 1]) {
			print("Bid is less than or equal to higest bid. Please bid higher.", true, false);
			continue;
		}
        else { 
            bid[player->getPlayerNum() - 1] = givingBid;
            highestPlayer = player->getPlayerNum();
        }
        copyLine.nextTurn();
        player = copyLine.frontLine();

    }

    if(bid[highestPlayer - 1] > 0) {
        player = line->findPlayer(highestPlayer);
        player->loseMoney(bid[highestPlayer - 1]);
        house->setOwner(player);

		print("Congratulations! " + player->getName() + " is now the owner of " + house->getName() + "!");
    }
    else {
		print("No one bought " + house->getName() + ".");
    }
}

void 
Monopoly::landOnLuxuryTaxTile() {
	shared_ptr<Player> currentPlayer(getCurrentPlayer());
	double tithe = currentPlayer->getMoney() * 0.1;
	if(tithe < 200) {
		print("Have to pay 10% of what you have.", true, false);
		currentPlayer->loseMoney((int)tithe);
	}
	else {
		print("Have to pay $200.", true, false);
		currentPlayer->loseMoney(200);
	}
}

void 
Monopoly::print(string s, bool wait, bool reset) {
	if(reset) {
		drawBoard();
	}
	cout << s << endl;
	if(wait) {
		getchar();
	}
	
}

void Monopoly::drawChanceCard() {
	int cardNum = rand() % 16;
	shared_ptr<Player> player = getCurrentPlayer();
	shared_ptr<Player> owner;
	int originalSpot = player->getLocationNum();
	shared_ptr<BoardTile> newSpot;
	print("Your card is: ", false, false);
	switch(cardNum)
	{
		case 0:
			print("Advance to Go (Collect $200).",true, false);
			movePlayerToSpot(0);
			break;
		case 1:
			print("Advance to Illinois Ave--If you pass Go, collect $200.", true, false);
			movePlayerToSpot(24);
			landOnHouseTile();
			break;
		case 2:
			// Locations for utilities are 12 and 28
			print("Advance token to nearest Utility. If unowned you may buy if from the Bank. If owned, throw dice and pay owner a total ten times the amount thrown.",true, false);
			movePlayerToSpot(originalSpot <= 12 || originalSpot > 28 ? 12 : 28);
			newSpot = board->getTile(player->getLocationNum());
			owner = newSpot->getOwner();
			print("You moved to " + newSpot->getName() + "!");
			if (owner) {
				roll();
				print("You rolled a " + to_string(getDie(1)) + " and a " + to_string(getDie(2)) + "!", false, false);	
				print("Had to pay $" + to_string(getRoll() * 10) + " to " + owner->getName() + ".", true, false);
				player->loseMoney(getRoll() * 10);
				owner->addMoney(getRoll() * 10);
			}
			else {
				askToBuyProperty(player, newSpot);
			}
			break;
		case 3:
			// Locations for railroads are 5, 15, 25, and 35
			print("Advance token to the nearest Railroad and pay owner twice the rental to which he/she is otherwise entitled. If Railroad is unowned, you may buy it from the Bank.", true, false);
			// player->goToSpot(player->getLocationNum() <= 15 ? abs())
			switch (originalSpot) 
			{
				case 0 ... 4: case 35 ... 39:
					movePlayerToSpot(5);
					break;
				case 5 ... 14:
					movePlayerToSpot(15);
					break;
				case 15 ... 24:
					movePlayerToSpot(25);
					break;
				case 25 ... 34:
					movePlayerToSpot(35);
					break;
			}
			newSpot = board->getTile(player->getLocationNum());
			print("You moved to " + newSpot->getName() + "!");			
			landOnRailroadTile(2);
			break;
		case 4:
			print("Bank pays you dividend of $50.", true, false);
			player->addMoney(50);
			break;
		case 5:
			print("Get out of Jail Free.", true, false);
			player->setOutOfJailCard(true);
			break;
		case 6:
			print("Go back 3 spaces.", true, false);
			movePlayerToSpot((originalSpot + 37) % 40, false);
			break;
		case 7:
			print("Go to Jail--go directly to jail--do not pass Go, do not collect $200.", true, false);
			sendPlayerToJail(player);
			break;
		case 8:
			print("Make general repairs on all your property--for each house pay $25--for each hotel $100.", true, false);
			payHouseRepairs(player);
			break;
		case 9:
			print("Pay poor tax of $15.", true, false);
			player->loseMoney(15);
			break;
		case 10:
			print("Take a trip to Reading Railroad--if you pass Go, collect $200.", true, false);
			movePlayerToSpot(5);
			landOnRailroadTile();
			break;
		case 11:
			print("Take a walk on the Boardwalk--advance token to Boardwalk.", true, false);
			movePlayerToSpot(39);
			landOnHouseTile();
			break;
		case 12:
			print("You have been elected Chairman of the Board. Pay each player $50.", true, false);
			payEachPlayer(50);
			break;
		case 13:
			print("Your building and loan matures--collect $150.", true, false);
			player->addMoney(150);
			break;
		case 14:
			print("You have won a crossword competition--collect $100.", true, false);
			player->addMoney(100);
			break;
		case 15:
			print("Advance to St. Charles Place--if you pass Go, collect $200.", true, false);
			movePlayerToSpot(11);
			landOnHouseTile();
			break;
	}
}

void
Monopoly::sendPlayerToJail(shared_ptr<Player> player) {
	if (player->hasOutOfJailCard()) {
		print("You have a 'Get Out of Jail' card! You skipped this time!");
		player->setOutOfJailCard(false);
		return;
	}
	player->goToJail();
}

void
Monopoly::moveCurrentPlayer(int roll) {
	shared_ptr<Player> player = getCurrentPlayer();
	int originalSpot = player->getLocationNum();
	player->move(roll);

	if(player->getLocationNum() < originalSpot) {
		print("You recieved $200!");
		player->addMoney(200);
	}
}

void
Monopoly::movePlayerToSpot(int val, bool getBonus) {
	shared_ptr<Player> player = getCurrentPlayer();
	int origionalSpot = player->getLocationNum();
	player->goToSpot(val);

	if(player->getLocationNum() < origionalSpot && getBonus) {
		print("You recieved $200!");
		player->addMoney(200);
	}
}

void
Monopoly::payEachPlayer(int val) {
	shared_ptr<Player> currentPlayer = getCurrentPlayer();
	line->nextTurn();
	for(int i = 0; i < line->getNumPlayers() - 1; i++) {
		getCurrentPlayer()->addMoney(50);
		line->nextTurn();
	}
	currentPlayer->loseMoney((line->getNumPlayers() - 1) * 50);

}

void
Monopoly::payHouseRepairs(shared_ptr<Player> player) {
	list<shared_ptr<HouseTile>> ownedHouses = getOwnedHouses(player);
	int total = 0;
	int numHouses;

	// list<HouseTile *>::iterator it;
	// for(it = ownedHouses.begin(); it != ownedHouses.end(); it++) {
	for (const auto tile:ownedHouses) {
		numHouses = tile->getNumHouses();
		if (numHouses <= 4) {
			total += numHouses * 25;
		}
		else {
			total += 100;
		}
	}

	player->loseMoney(total);
	print("You had to pay $" + to_string(total) + ".");
}

list<shared_ptr<HouseTile>> 
Monopoly::getOwnedHouses(shared_ptr<Player> player) {
	list<shared_ptr<HouseTile>> ownedHouses;
	shared_ptr<BoardTile> tile;
	shared_ptr<Player> owner;
	int playerNum = player->getPlayerNum();
	for(int i = 0; i < 40; i++) {
		tile = board->getTile(i);
		owner = tile->getOwner();
		if(owner && tile->getType() == HOUSE && owner->getPlayerNum() == playerNum) {
			ownedHouses.push_back(static_pointer_cast<HouseTile>(tile));
		}
	}

	return ownedHouses;
}

void
Monopoly::payRentTo(shared_ptr<Player> player, shared_ptr<Player> owner, shared_ptr<BoardTile> newSpot, int multiply, int roll) {
	print("You have to pay $" + to_string(newSpot->getRent(roll) * multiply) + " rent to " + owner->getName() + ".");
	player->loseMoney(newSpot->getRent(roll) * multiply);
	owner->addMoney(newSpot->getRent(roll) * multiply);
} 

shared_ptr<Player>
Monopoly::getPlayerById(int id) {
	PlayerLine copyLine = *line;
	shared_ptr<Player> player;
	for (int i = 0; i < copyLine.getNumPlayers(); i++) {
		player = copyLine.frontLine();
		if (player->getPlayerNum() == id) return player;
		copyLine.nextTurn();
	}
}

void 
Monopoly::endLine(int playerId) {
	if(playerId > 0 && playerId <= line->getNumPlayers()) {
		shared_ptr<Player> player = getPlayerById(playerId);
		if (player->getPlayerNum() == getCurrentPlayer()->getPlayerNum()) {
			cout << "*";
		}
		cout << player->getName() << ": $" << player->getMoney(); 
	}
	cout << endl;
}

void 
Monopoly::drawBoard() {
    PlayerLine copyLine;
    copyLine = *line;
	int numPlayers = copyLine.getNumPlayers();

    //x and y places of each player and 'where' represents the top(1), middle(2), and bottom(3) parts of the board
	int px[numPlayers], py[numPlayers], pNum[numPlayers], where[numPlayers]; //x is j and y is i in the for loops down below
	shared_ptr<Player> player(copyLine.frontLine());
	
	system(CMD);

	//Resets copy of line to player 1 being in the front
	while(player->getPlayerNum() != 1)
	{
		copyLine.nextTurn();
		player = copyLine.frontLine();
	}
		
	for(int i = 0; i < numPlayers; i++)
	{
		player = copyLine.frontLine();
		pNum[i] = player->getPlayerNum();
		switch(player->getLocationNum())
		{
			case 0:				//Starting at the bottom right of the board
				px[i] = 111 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 1:
				px[i]= 100 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 2:
				px[i] = 89 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 3:
				px[i] = 78 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 4:
				px[i] = 67 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 5:
				px[i] = 56 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 6:
				px[i] = 45 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 7:
				px[i] = 34 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 8:
				px[i] = 23 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 9:
				px[i] = 12 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 10:
				if (player->inJail())
					px[i] = 6 + i;
				else 
					px[i] = 1 + i;
				py[i] = 2;
				where[i] = 3;
				break;
			case 11:			//Beginning of bottom left corner
				px[i] = 1 + i;
				py[i] = 34;
				where[i] = 2;
				break;
			case 12:	
				px[i] = 1 + i;
				py[i] = 30;
				where[i] = 2;
				break;
			case 13:
				px[i] = 1 + i;
				py[i] = 26;
				where[i] = 2;
				break;
			case 14:
				px[i] = 1 + i;
				py[i] = 22;
				where[i] = 2;
				break;
			case 15:
				px[i] = 1 + i;
				py[i] = 18;
				where[i] = 2;
				break;
			case 16:
				px[i] = 1 + i;
				py[i] = 14;
				where[i] = 2;
				break;
			case 17:
				px[i] = 1 + i;
				py[i] = 10;
				where[i] = 2;
				break;
			case 18:
				px[i] = 1 + i;
				py[i] = 6;
				where[i] = 2;
				break;
			case 19:
				px[i] = 1 + i;
				py[i] = 2;
				where[i] = 2;
				break;
			case 20:				//Start of the top left corner
				px[i] = 1 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 21:				
				px[i] = 12 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 22:				
				px[i] = 23 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 23:				
				px[i] = 34 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 24:				
				px[i] = 45 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 25:				
				px[i] = 56 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 26:				
				px[i] = 67 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 27:				
				px[i] = 78 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 28:				
				px[i] = 89 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 29:				
				px[i] = 100 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 30:				
				px[i] = 111 + i;
				py[i] = 2;
				where[i] = 1;
				break;
			case 31:				//Start of top right corner
				px[i] = 111 + i;
				py[i] = 2;
				where[i] = 2;
				break;
			case 32:
				px[i] = 111 + i;
				py[i] = 6;
				where[i] = 2;
				break;
			case 33:
				px[i] = 111 + i;
				py[i] = 10;
				where[i] = 2;
				break;
			case 34:
				px[i] = 111 + i;
				py[i] = 14;
				where[i] = 2;
				break;
			case 35:
				px[i] = 111 + i;
				py[i] = 18;
				where[i] = 2;
				break;
			case 36:
				px[i] = 111 + i;
				py[i] = 22;
				where[i] = 2;
				break;
			case 37:
				px[i] = 111 + i;
				py[i] = 26;
				where[i] = 2;
				break;
			case 38:
				px[i] = 111 + i;
				py[i] = 30;
				where[i] = 2;
				break;
			case 39:
				px[i] = 111 + i;
				py[i] = 34;
				where[i] = 2;
				break;
			default:
				cout << "ERROR: Hit default!!!" << endl;
				break;	
		}
		copyLine.nextTurn();
	}

	//Shows the top of the board
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 122; j++)
		{
			for (int k = 0; k < numPlayers; k++)
			{
				if (j == px[k] && i == py[k] && where[k] == 1)
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
		endLine(i + 1);
	}
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;

	//The sides of the board
	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 122; j++)
		{
			for (int k = 0; k < numPlayers; k++)
			{
				if (j == px[k] && i == py[k] && where[k] == 2)
				{
					cout << k + 1;
					j++;
				}
			}
			if ((i + 1) % 4 == 0 && i != 0 && i != 45 && ((j >= 0 && j <= 11) || j >= 110))
				cout << "-";
			else if (i == 0 && j == 2)
			{
				cout << "New York";
				j += 7;
			}
			else if ((i == 1 || i == 5 || i == 13 || i == 21) && (j == 2 || j == 112) )
			{
				cout << "Avenue";
				j += 5;
			}
			else if (i == 0 && j == 112)
			{
				cout << "Pacific";
				j += 6;
			}
			else if (i == 4 && j == 2)
			{
				cout << "Tenessee";
				j += 7;
			}
			else if (i == 4 && j == 112)
			{
				cout << "N. Carol.";
				j += 8;
			}
			else if (i == 8 && (j == 2 || j == 112))
			{
				cout << "Community";
				j += 8;
			}
			else if (i == 9 && (j == 2 || j == 112))
			{
				cout << "Chest";
				j += 4;
			}
			else if (i == 12 && j == 2)
			{
				cout << "St James";
				j += 7;
			}
			else if (i == 13 && j == 2)
			{
				cout << "Place";
				j += 4;
			}
			else if (i == 12 && j == 112)
			{
				cout << "Penn.";
				j += 4;
			}
			else if (i == 16 && j == 2)
			{
				cout << "Penn.";
				j += 4;
			}
			else if (i == 17 && j == 2)
			{
				cout << "Railroad";
				j += 7;
			}
			else if (i == 16 && j == 112)
			{
				cout << "Short";
				j += 4;
			}
			else if (i == 17 && j == 112)
			{
				cout << "Line";
				j += 3;
			}
			else if (i == 20 && j == 2)
			{
				cout << "Virginia";
				j += 7;
			}
			else if (i == 20 && j == 112)
			{
				cout << "Chance";
				j += 5;
			}
			else if (i == 24 && j == 2)
			{
				cout << "States";
				j += 5;
			}
			else if (i == 25 && j == 2)
			{
				cout << "Avenue";
				j += 5;
			}
			else if (i == 24 && j == 112)
			{
				cout << "Park";
				j += 3;
			}
			else if (i == 25 && j == 112)
			{
				cout << "Place";
				j += 4;
			}
			else if (i == 28 && j == 2)
			{
				cout << "Electric";
				j += 7;
			}
			else if (i == 29 && j == 2)
			{
				cout << "Company";
				j += 6;
			}
			else if (i == 28 && j == 112)
			{
				cout << "Luxury";
				j += 5;
			}
			else if (i == 29 && j == 112)
			{
				cout << "Tax";
				j += 2;
			}
			else if (i == 32 && j == 2)
			{
				cout << "St Char.";
				j += 7;
			}
			else if (i == 33 && j == 2)
			{
				cout << "Place";
				j += 4;
			}
			else if (i == 32 && j == 112)
			{
				cout << "Boardwalk";
				j += 8;
			}
			else if (j == 0 || j == 11 || j == 110 || j == 121)
				cout << "|";
			else 
				cout << " ";
		}
		endLine(i + 4);
	}
	//The bottom of the board
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 122; j++)
		{
			for (int k = 0; k < numPlayers; k++)
			{
				if (j == px[k] && i == py[k] && where[k] == 3)
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
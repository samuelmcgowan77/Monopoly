#include "Monopoly.h"

Monopoly::Monopoly(Board *b, shared_ptr<PlayerLine> l) {
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
    dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;
    
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

            while (answered) {
				print("Would you like to get out of jail for $50? (y/n)", false, false);
                cin >> ans;
				getchar();

                if(ans == "y") {
                    player->loseMoney(50);
					print("You now have $" + to_string(player->getMoney()) + ".", true, false);
                    player->getOutOfJail();
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
    int r = roll();
    if(rollDoubles()) {
		print("You got doubles!", true, false);
        player->getOutOfJail();
    }
    else {
        if(p->getTurnsInJail() >= 3) {
            if(!player->ableToPay(50)) {
				print("You could not pay the $50 bail! GAME OVER FOR YOU!");
                p->exitGame();
				return;
            }
            else {;
                player->loseMoney(50);
				print("Had to pay $50 bail. Now have $" + to_string(p->getMoney()) + ".", true, false);
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

BoardTile*
Monopoly::getCurrentTile() {
    int loc = getCurrentPlayer()->getLocationNum();
    return board->getTile(loc);
}

void 
Monopoly::landOnHouseTile() {
    string ans;
    bool answered = false;

    HouseTile *houseTile = (HouseTile *)getCurrentTile();
    shared_ptr<Player> owner(houseTile->getOwner());
    shared_ptr<Player> player(getCurrentPlayer());

    if(!houseTile->getOwner()) {
        if(houseTile->getCostToBuy() > player->getMoney()) {
			print("You do not have enough funds to buy this house.", true, false);
            return;
        }
        while(!answered) {
			print("Would you like to buy the house? The cost is (y/n)", false, false);
            cin >> ans;
			getchar();
            if(ans == "y") {
                player->loseMoney(houseTile->getCostToBuy());
                houseTile->setOwner(player);
				print("Congratulations! You bought " + houseTile->getName() + "!");
                answered = true;
            }
            else if(ans == "n") {
                auctionHouse(houseTile);
                answered = true;
            }
            else {
				print("Please enter a valid answer.", false, true);
            }
        }
    } else if(!houseTile->isMortgaged()) {
        player->loseMoney(houseTile->getRent());
        owner->addMoney(houseTile->getRent());
		print("Had to pay rent to " + owner->getName(), true, false);
    }
}

void 
Monopoly::auctionHouse(HouseTile *house) {
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
			print("Highest Bid: " + to_string(bid[highestPlayer - 1]) + " from " + winningPlayer->getName() + "!", false, false);
        }

		print( player->getName() + ", what would you like to bid? Enter -1 to not bid anymore.", false, false);
        cin >> givingBid;
		getchar();
        if(givingBid > player->getMoney()) {
			print("Bid is higher than what you currently have. Please bid lower.", true, false);
        }
        else if(givingBid < 0) {
            copyLine.pop();
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
        player->loseMoney(house->getCostToBuy());
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

void 
Monopoly::drawBoard() {
    PlayerLine copyLine;
    copyLine = *line;

    //x and y places of each player and 'where' represents the top(1), middle(2), and bottom(3) parts of the board
	int px[copyLine.getNumPlayers()], py[copyLine.getNumPlayers()], pNum[copyLine.getNumPlayers()], where[copyLine.getNumPlayers()]; //x is j and y is i in the for loops down below
	shared_ptr<Player> player(copyLine.frontLine());
	
	system("clear");

	//Resets copy of line to player 1 being in the front
	while(player->getPlayerNum() != 1)
	{
		copyLine.nextTurn();
		player = copyLine.frontLine();
	}
		
	for(int i = 0; i < copyLine.getNumPlayers(); i++)
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
					px[i] = 10 - i;
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
			for (int k = 0; k < copyLine.getNumPlayers(); k++)
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
		cout << endl;
	}
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;
	//The sides of the board
	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 122; j++)
		{
			for (int k = 0; k < copyLine.getNumPlayers(); k++)
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
			cout << endl;
	}
	//The bottom of the board
	for (int i = 0; i < 122; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 122; j++)
		{
			for (int k = 0; k < copyLine.getNumPlayers(); k++)
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
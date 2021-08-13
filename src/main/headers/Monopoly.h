#include "Board.h"
#include "HouseTile.h"
#include "PlayerLine.h"
#include "RailroadTile.h"
#include "SpecialTile.h"
#include "UtilityTile.h"
#include<iostream>
#include<cstdlib>
#include<memory>

class Monopoly {
    private: 
        int dice1;
        int dice2;
        Board* board;
        shared_ptr<PlayerLine> line;
    public:
        Monopoly(Board* b, shared_ptr<PlayerLine> l);
        void drawBoard();
        void drawCommunityChest();
        void drawChanceCard();
        int roll();
        bool rollDoubles();
        int getRoll();
        int getDie(int v);
        void attemptOutOfJail();
        void rollDiceInJail(shared_ptr<Player> player);
        Player *getNextPlayer();
        bool gameOver();
        void landOnHouseTile();
        void auctionHouse(HouseTile *house);
        void landOnLuxuryTaxTile();
        shared_ptr<Player> getCurrentPlayer();
        BoardTile *getCurrentTile();
        void print(string s, bool wait=true, bool reset=true);
};
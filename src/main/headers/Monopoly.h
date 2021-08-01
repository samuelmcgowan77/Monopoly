#include "Board.h"
#include "HouseTile.h"
#include "PlayerLine.h"
#include "RailroadTile.h"
#include "SpecialTile.h"
#include "UtilityTile.h"
#include<iostream>
#include<cstdlib>

class Monopoly {
    private: 
        int dice1;
        int dice2;
        Board *board;
        PlayerLine *line;
    public:
        Monopoly(Board *b, PlayerLine *l);
        void drawBoard();
        void drawCommunityChest();
        void drawChanceCard();
        int roll();
        bool rollDoubles();
        int getRoll();
        int getDie(int v);
        void attemptOutOfJail();
        void rollDiceInJail(Player *p);
        Player *getNextPlayer();
        bool gameOver();
        void landOnHouseTile();
        void auctionHouse(HouseTile *house);
        void landOnLuxuryTaxTile();
        Player *getCurrentPlayer();
        BoardTile *getCurrentTile();
        void print(string s, bool wait=true, bool reset=true);
};
#include "Board.h"
#include "HouseTile.h"
#include "PlayerLine.h"
#include "RailroadTile.h"
#include "SpecialTile.h"
#include "UtilityTile.h"
#include<iostream>
#include<cstdlib>
#include<memory>
#include<list>

class Monopoly {
    private: 
        int dice1;
        int dice2;
        Board *board;
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
        void sendPlayerToJail(shared_ptr<Player> player);
        void moveCurrentPlayer(int roll);
        void movePlayerToSpot(int val, bool getBonus=true);
        // Player *getNextPlayer();
        bool gameOver();
        void landOnHouseTile();
        void landOnRailroadOrUtility();
        void askToBuyProperty(shared_ptr<Player> player, BoardTile* propertyTile);
        void auctionHouse(HouseTile *house);
        void landOnLuxuryTaxTile();
        shared_ptr<Player> getCurrentPlayer();
        shared_ptr<Player> getPlayerById(int id);
        BoardTile *getCurrentTile();
        void payEachPlayer(int val);
        void payHouseRepairs(shared_ptr<Player> player);
        list<HouseTile *> getOwnedHouses(shared_ptr<Player> player);
        list<BoardTile *> getOwnedProperties(shared_ptr<Player> player);
        void payRentTo(shared_ptr<Player> player, shared_ptr<Player> owner, BoardTile* newSpot, int multiply=1);
        void playerLoseMoney(int val);
        void askToSellProperty();
        void endLine(int PlayerId);
        void print(string s, bool wait=true, bool reset=true);
};
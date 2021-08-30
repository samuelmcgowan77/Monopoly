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
        shared_ptr<Board> board;
        shared_ptr<PlayerLine> line;
    public:
        Monopoly(shared_ptr<Board> b, shared_ptr<PlayerLine> l);
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
        void landOnRailroadTile(int multiply=1);
        void landOnUtilityTile();
        void askToBuyProperty(shared_ptr<Player> player, shared_ptr<BoardTile> propertyTile);
        void auctionHouse(shared_ptr<HouseTile> house);
        void landOnLuxuryTaxTile();
        shared_ptr<Player> getCurrentPlayer();
        shared_ptr<Player> getPlayerById(int id);
        shared_ptr<BoardTile> getCurrentTile();
        void payEachPlayer(int val);
        void payHouseRepairs(shared_ptr<Player> player);
        list<shared_ptr<HouseTile>> getOwnedHouses(shared_ptr<Player> player);
        list<shared_ptr<BoardTile>> getOwnedProperties(shared_ptr<Player> player);
        void payRentTo(shared_ptr<Player> player, shared_ptr<Player> owner, shared_ptr<BoardTile> newSpot, int multiply=1, int roll=0);
        void playerLoseMoney(int val);
        void askToSellProperty();
        void endLine(int PlayerId);
        void print(string s, bool wait=true, bool reset=true);
};
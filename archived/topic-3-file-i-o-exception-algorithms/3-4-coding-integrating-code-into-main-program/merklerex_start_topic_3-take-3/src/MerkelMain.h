#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
    public:
        MerkelMain() = default;                        // default constructor
        /** Call this to start the sim */
        void init();
    private: 
        void loadOrderBook();

        void printMenu();

        void printHelp();
        void printMarketStats();
        void enterAsk();                      // void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();

        int getUserOption();

        void exitApp();
        void processInvalidUserInput();

        void processUserOption(int userOption);

        std::vector<OrderBookEntry> orders;

};

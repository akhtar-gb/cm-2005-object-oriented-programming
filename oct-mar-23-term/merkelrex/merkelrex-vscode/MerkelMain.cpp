#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"


void MerkelMain::init()
{
    loadOrderBook();
    int input;                      // int userOption;                  
    while(true)
    {
        printMenu();
        input = getUserOption();    // userOption = getUserOption();
        processUserOption(input);   // processUserOption(userOption);
    };
};

void MerkelMain::loadOrderBook()
{

    orders = CSVReader::readCSV("20200317.csv");
    std::cout << "MerkelMain::loadOrderBookread " << orders.size() << " orders" << std::endl;
     
};

void MerkelMain::printMenu()
{
    std::cout << "1: Print help " << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Make an ask " << std::endl;
    std::cout << "4: Make a bid " << std::endl;
    std::cout << "5: Print wallet " << std::endl;
    std::cout << "6: Continue " << std::endl;
    std::cout << "7: Exit " << std::endl;

    std::cout << "============== " << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money." << std::endl;
    std::cout << "Analyse the market and make bids" << std::endl;
    std::cout << "and offers. " << std::endl;
    std::cout << "Choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions \n" << std::endl;
}

void MerkelMain::printMarketStats()
{
    std::cout << "Check ask/bid rates" << std::endl;
    std::cout << "and compare to other exchanges \n" << std::endl;
    std::cout << "OrderBook contains :  " << orders.size() << " entries" << std::endl;
    unsigned int bids = 0;
    unsigned int asks = 0;
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == OrderBookType::ask) asks++;
        if (e.orderType == OrderBookType::bid) bids++;
    };
    std::cout << "Order Book asks: " << asks << " | bids: " << bids << std::endl;
};

void MerkelMain::enterAsk()
{
    std::cout << "Place a sell call to the exchange" << std::endl;
    std::cout << "and wait for buyers \n" << std::endl;
    std::cout << "Make an offer - enter the amount " << std::endl;
};

void MerkelMain::enterBid()
{
    std::cout << "Place a bid for your order" << std::endl;
    std::cout << "and wait for sellers \n" << std::endl;
    std::cout << "Make a bid - enter the amount" << std::endl;
};

void MerkelMain::printWallet()
{
    std::cout << "Check your wallet" << std::endl;
    std::cout << "and see how much you have \n" << std::endl;
    std::cout << "Your wallet is empty. " << std::endl;
};
        
void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Go to the next time frame" << std::endl;
    std::cout << "and select the next option \n" << std::endl;
};

void MerkelMain::exitApp()
{
    std::cout << "Exiting" << std::endl;
    exit(0);
};
 
int MerkelMain::getUserOption()
{
    std::cout << "Type in 1-7" << std::endl;

    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
};

void MerkelMain::processInvalidUserInput(){
    std::cout << ">> You have entered an invalid option" << std::endl;
    std::cout << "please try again" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
};

void MerkelMain::processUserOption(int userOption)
{

    switch (userOption)
        {
            case 1:
                printHelp();
                break;
                
            case 2:
                printMarketStats();
                break;
                
            case 3:
                enterAsk();
                break;
                
            case 4:
                enterBid();
                break;
                
            case 5:
                printWallet();
                break;
                
            case 6:
                gotoNextTimeframe();
                break;
                
            case 7:
                exitApp();
                break;
                
            default:
                processInvalidUserInput();
                break;
    };
};



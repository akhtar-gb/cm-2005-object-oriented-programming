#include <iostream>
#include <string>
#include <vector>

void printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue   
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
}

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void  printMarketStats()
{
    std::cout << "Market looks good. " << std::endl;
}

void enterOffer()
{
    std::cout << "Mark and offer - enter the amount " << std::endl;
}

void enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
}
 
int getUserOption()
{
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1) // bad input
    {
        printHelp();
    }
    if (userOption == 2) // bad input
    {
        printMarketStats();
    }
    if (userOption == 3) // bad input
    {
        enterOffer();
    }
    if (userOption == 4) // bad input
    {
        enterBid();
    }
    if (userOption == 5) // bad input
    {
        printWallet();
    }
    if (userOption == 6) // bad input
    {
        gotoNextTimeframe();
    }       
}

int main()
{   

    enum class OrderBookType { bid, ask };

    // double price = 5319.450228;
    // double amount = 0.00020075;

    // std::string timestamp {"2020/03/17 17:01:24.884492"};
    // std::string product {"BTC/USDT"};
    // std::string ordertype{"bid"};

    
    // OrderBookType ordertype = OrderBookType::bid;


    std::vector<double> prices {5319.450228};
    std::vector<double> amounts {0.00020075};
    std::vector<std::string> timestamps {"2020/03/17 17:01:24.884492"};
    std::vector<std::string> products {"BTC/USDT"};
    std::vector<OrderBookType> ordertypes {OrderBookType::bid};

    prices.push_back(5319.450228);
    amounts.push_back(0.00020075);
    timestamps.push_back("2020/03/17 17:01:24.884492");
    products.push_back("BTC/USDT");
    ordertypes.push_back(OrderBookType::bid);








    while (true)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);

        std::cout << "prices[0] = " << prices[0] << std::endl;
        std::cout << "amounts[0] = " << amounts[0] << std::endl;
    }
    return 0;
}


#include <iostream>
#include <string>
#include <vector>


// classe decalrations
enum class OrderBookType { bid, ask };

class OrderBookEntry{
    
    public:

    // OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderBookType ordertype){
    //     this->price = price;
    //     this->amount = amount;
    //     this->timestamp = timestamp;
    //     this->product = product;
    //     this->ordertype = ordertype;
    // }

    OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _ordertype): 
                    price(_price), amount(_amount), timestamp(_timestamp), product(_product), ordertype(_ordertype)
    
    {
        // price = _price;
        // amount = _amount;
        // timestamp = _timestamp;
        // product = _product;
        // ordertype = _ordertype;
    }

    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType ordertype;

};

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
};

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
};

void  printMarketStats()
{
    std::cout << "Market looks good. " << std::endl;
};

void enterOffer()
{
    std::cout << "Mark and offer - enter the amount " << std::endl;
};

void enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
};

void printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
};
        
void gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
};
 
int getUserOption()
{
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
};

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
};

int main()
{   

    // double price = 5319.450228;
    // double amount = 0.00020075;

    // std::string timestamp {"2020/03/17 17:01:24.884492"};
    // std::string product {"BTC/USDT"};
    // std::string ordertype{"bid"};

    
    // OrderBookType ordertype = OrderBookType::bid;


    // std::vector<double> prices {5319.450228};
    // std::vector<double> amounts {0.00020075};
    // std::vector<std::string> timestamps {"2020/03/17 17:01:24.884492"};
    // std::vector<std::string> products {"BTC/USDT"};
    // std::vector<OrderBookType> ordertypes {OrderBookType::bid};

    // prices.push_back(5319.450228);
    // amounts.push_back(0.00020075);
    // timestamps.push_back("2020/03/17 17:01:24.884492");
    // products.push_back("BTC/USDT");
    // ordertypes.push_back(OrderBookType::bid);


    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUserOption(userOption);

    //     std::cout << "prices[0] = " << prices[0] << std::endl;
    //     std::cout << "amounts[0] = " << amounts[0] << std::endl;
    // }

    
    /* Create vector to store order book entries*/
    std::vector<OrderBookEntry> orders;

    //instantiate an object
    // OrderBookEntry order1{5319.450228, 0.00020075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid}; 
    // OrderBookEntry order2{5679.350199, 0.00021075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid};
        
    // code block to test the object with no constructor
        //set the data values
        // order1.price = 5319.450228;
        // order1.amount = 0.00020075;
        // order1.timestamp = "2020/03/17 17:01:24.884492";
        // order1.product = "BTC/USDT";
        // order1.ordertype = OrderBookType::bid;

    orders.push_back(OrderBookEntry{5319.450228, 0.00020075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});
    orders.push_back(OrderBookEntry{5679.350199, 0.00021075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});

    // std::cout << "Order 1 Price: " << orders[0].price << std::endl;
    // std::cout << "Order 2 Price: " << orders[1].price << std::endl;

    // iteration over the vector

    // range based for loop by value and copy
    for (OrderBookEntry order : orders)
    {
        std::cout << "Price: " << order.price << std::endl;
        // std::cout << "Amount: " << order.amount << std::endl;
        // std::cout << "Timestamp: " << order.timestamp << std::endl;
        // std::cout << "Product: " << order.product << std::endl;
        // std::cout << "Order Type: " << order.ordertype << std::endl;
    }

    // range based for loop by reference
    for(OrderBookEntry& order : orders)
    {
        std::cout << "Price: " << order.price << std::endl;
    }

    //index style array
    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "Price: " << orders[i].price << std::endl;
    }

    //object style
    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "Price: " << orders.at(i).price << std::endl;
    }

    return 0;
};


//
//  main.cpp
//  Merkelex
//
//  Created by Akhtar on 12/06/2023.
//

// last completed worksheet 2-313

#include <iostream>
#include <string>
#include "vector"

enum class OrderBookType {bid, ask};

class OrderBookEntry{
    
    public:
    
    // data book entry constructor method
    OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _orderType, double _price, double _amount):
                    timestamp(_timestamp), product(_product), orderType(_orderType), price(_price), amount(_amount)
    {

    };
    
    // class data members
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
    double price;
    double amount;
        
};

//// -- start -- this code block does not work as given in the worksheet 2313 - hence commented out
//OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _orderType, double _price, double _amount):
//                                timestamp(_timestamp), product(_product), orderType(_orderType), price(_price), amount(_amount)
//// -- end -- this code block does not work as given in the worksheet 2313 - hence commented out
//{
//    // -- with member initialisation lists the following assignments to parameters are not needed
////    timestamp = _timestamp;
////    product = _product;
////    orderType = _orderType;
////    price = _price;
////    amount = _amount;
//};

void printMenu(){
    //print menu
    std::cout << "Welcome to Simulated Trading \n" << std::endl;
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Place an ask" << std::endl;
    std::cout << "4: Place a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "=========================== " << std::endl;
};

// menu functions /////////////////////////////
void printHelp(){
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions \n" << std::endl;
};

void printMarketStats(){
    std::cout << "Check ask/bid rates" << std::endl;
    std::cout << "and compare to other exchanges \n" << std::endl;
};

void enterOffer(){
    std::cout << "Place a sell call to the exchange" << std::endl;
    std::cout << "and wait for buyers \n" << std::endl;
};

void enterBid(){
    std::cout << "Place a bid for your order" << std::endl;
    std::cout << "and wait for sellers \n" << std::endl;
};

void printWallet(){
    std::cout << "Check your wallet" << std::endl;
    std::cout << "and see how much you have \n" << std::endl;
};

void gotToTheNextTimeFrame(){
    std::cout << "Go to the next Time Frame" << std::endl;
    std::cout << "and select the next option \n" << std::endl;
};

// read user input
int getUserOption(){
    int userOption;
    
    std::cout << ">>> Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << "\n" << std::endl;
    return userOption;
};

// user options processing
void processUserOption(int userOption){
    // respond to user input
    switch (userOption) {
        case 1:
            printHelp();
            break;
            
        case 2:
            printMarketStats();
            break;
            
        case 3:
            enterOffer();
            break;
        
        case 4:
            enterBid();
            break;
            
        case 5:
            printWallet();
            break;
            
        case 6:
            gotToTheNextTimeFrame();
            break;
        default:
            std::cout << ">> You have entered an invalid option" << std::endl;
            std::cout << "please try again" << std::endl;
            std::cout << "-------------------------------------" << std::endl;
            break;
    };
};

// challenge from 2.311
double computeAveragePrice(){
    
    return 0.00;
};

// main function
int main(int argc, const char * argv[]) {
    // insert code here...
    
    // data types to model from the datastream
    
    // create a vector for data tyoes
    std::vector<std::string> timestamps;
    std::vector<std::string> products;
    std::vector<OrderBookType> orderTypes;
    std::vector<double> prices;
    std::vector<double> amounts;
    

       
//    while(true){
//        printMenu();
//        int userOption = getUserOption();
//        processUserOption(userOption);
//
//
//
//    };
    
    // -- start - test for printing out hardcoded values pushed into vectors
//    timestamps.push_back("2020/03/17 17:01:24.884492");
//    timestamps.push_back("2020/03/17 18:01:24.884492");
//    std::cout << "First row timestamp " << timestamps[0] << "\n";
//    std::cout << "Second row timestamp " << timestamps[1] << "\n";
//
//    amounts.push_back(0.5);
//    amounts.push_back(0.125);
//    std::cout << "First row amount " << amounts[0] << std::endl;
//    std::cout << "Second row amount " << amounts[1] << std::endl;
    // -- end - test for printing out hardcoded values pushed into vectors
    
    // oredr book entry vector of objects
    std::vector<OrderBookEntry> entries;
    entries.push_back(OrderBookEntry{"2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask, 5319.450228, 0.00020075});
    entries.push_back(OrderBookEntry{"2020/03/18 18:01:24.884492", "ETH/BTC", OrderBookType::ask, 5000.010001, 0.00020000});
    
    for (OrderBookEntry& e : entries){
            std::cout << "Order price: " << e.price << std::endl;
    }
  
    return 0;
};


/*

 // stand-in test data
 std::string timestamp{"2020/03/17 17:01:24.884492"};
 std::string product{"ETH/BTC"};
 OrderBookType orderType = OrderBookType::ask;
 double price {5319.450228};
 double amount {0.00020075};
 */

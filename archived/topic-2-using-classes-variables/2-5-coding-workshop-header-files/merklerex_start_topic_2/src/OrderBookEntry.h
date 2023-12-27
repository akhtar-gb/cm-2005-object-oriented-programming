#pragma once

#include <string>

// header file contains specifications of the class
// classe decalrations
enum class OrderBookType { bid, ask };

class OrderBookEntry{
    
    public:

        // constructor with no return type - takes in OrderBookEntry class variables as parameters
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _ordertype); 

        // variables
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType ordertype;

};
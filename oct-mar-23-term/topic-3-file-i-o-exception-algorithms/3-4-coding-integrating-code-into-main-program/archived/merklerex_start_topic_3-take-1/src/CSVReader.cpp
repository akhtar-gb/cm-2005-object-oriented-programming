#include "CSVReader.h"

#include <iostream>

// constructor
CSVReader::CSVReader(){


}

// read the CSV file and return a vector of OrderBookEntry objects
std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile){
    std::vector<OrderBookEntry> entries;
    return entries;
};
std::vector<std::string> CSVReader::tokenise(std::string s, char delimiter){
    std::vector<std::string> tokens;
    return tokens;
};

// convert a vector of strings to an OrderBookEntry object
OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens){

    double price, amount;
    // check the size of the tokens vector is equal to the number of columns in the CSV file
    if (tokens.size() != 5){
        std::cout << "Error: tokens size is not 5" << std::endl;
        throw std::exception{};
    }

    try{
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch(const std::exception& e){
        std::cout << "Error: " << tokens[3] << std::endl;
        std::cout << "Error: " << tokens[4] << std::endl;
        throw;
    }

    // create an OrderBookEntry object from the tokens
    OrderBookEntry obe{ price, 
                        amount,
                        // timestamp
                        tokens[0], 
                        // product
                        tokens[1],
                        // convert the string to an OrderBookType
                        OrderBookEntry::stringToOrderBookType(tokens[2])};
    return obe;
};
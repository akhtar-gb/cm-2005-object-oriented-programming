#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader(){ // constructor
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFileName){ // read the CSV file and return a vector of OrderBookEntry objects
    
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{csvFileName};
    std::string line;
    
    if (csvFile.is_open()){

        while (std::getline(csvFile, line))  
        {
            try{
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
                entries.push_back(obe);
            }
            catch(const std::exception& e){
                std::cout << "CSVReader::readCSV() - bad data " << std::endl;
            }    
        }// end while 
    }
    std::cout << "CSVReader::readCSV() - returning " << entries.size() << " entries." << std::endl;
    return entries;
};

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator){ // split a string into a vector of strings
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do{
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) break;
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
        start = end + 1;
    }
    while (end != std::string::npos);
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
#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>

// TODO: Add the CSVReader class here.
class CSVReader
{
    public:

        // constructor
        CSVReader() = default;

        // a stateless function to fetch data from a CSV File 
        static std::vector<OrderBookEntry> readCSV(std::string csvFileName);

    private:
        // a stateless function to split a string into a vector of strings - tokenising
        static std::vector<std::string> tokenise(std::string s, char delimiter);
        // get a vector of strings from tokenise and convert it to an OrderBookEntry
        static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
};
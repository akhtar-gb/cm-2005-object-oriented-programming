#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// string csvLine = 'thing0,thing1,thing2' ## the string we are processing
// function which returns a vector of strings 
std::vector<std::string> tokensie(std::string csvLine, char separator){

    std::vector<std::string> tokens; // stores the tokens    
    signed int start, end; // used to delineate the position of the tokens
    std::string token;

    // start = csvLine.find_first_not_of(separator)
    start = csvLine.find_first_not_of(separator, 0);

    // do
    do{
        // end = next 'separator' after start
        end = csvLine.find_first_of(separator, start);
        // if start == csvLine.length or start == end ## nothing more to find
        // break
        if (start == csvLine.length() || start == end) break;

        // if end >= 0 ## we found the separator
        //     token = csvLine.substr(start, end - start) ## start, substring length
        if (end >= 0) token = csvLine.substr(start, end - start);

        // else ## end is invalid
        else token = csvLine.substr(start, csvLine.length() - start);

        // add token to the end of the tokens vector
        tokens.push_back(token);

        // start = end + 1 ## move past this token
        start = end + 1;
    }
    // while (end > 0) ## continue loop condition
    // because find_first_not_of returns std::string::npos if it does not find the search term.  
    while (end != std::string::npos);
    
    return tokens;
};

int main(){

    // // create a variable to store the tokens
    // std::vector<std::string> tokens;

    // // exmaple input string
    // // std::string s = "thing0,thing1,thing2";
    // std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";

    // // call the function
    // tokens = tokensie(s, ',');

    // for (std::string& t : tokens){
    //     std::cout << t << std::endl;
    // };

    // open the file with instance of ifstream abd pass in the file name
    std::ifstream csvFile{"20200317.csv"};
    // create a string variable to store the line
    std::string line;
    // create a vector of strings - variable - to store the tokens
    std::vector<std::string> tokens;

    if (csvFile.is_open()){
        std::cout << "File opened successfully" << std::endl;

        while(std::getline(csvFile, line)){
            std::cout << "Line read: " << line << std::endl;
            tokens = tokensie(line, ',');

            // check the size of the tokens vector is equal to the number of columns
            if (tokens.size() != 5){
                std::cout << "Error: tokens size is not 5" << std::endl;
                continue;
            }

            try{
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << "Price: " << price << std::endl;
                std::cout << "Amount: " << amount << std::endl;
            }
            catch(std::exception& e){
                std::cout << "Error: " << tokens[3] << std::endl;
                std::cout << "Error: " << tokens[4] << std::endl;
                break;
            }

            // convert the tokens to the correct data type


            // for (std::string& t : tokens){
            //     std::cout << t << std::endl;
            // };

            std::cout << "------------------------" << std::endl;
        };

        csvFile.close();
    }
    else{
        std::cout << "File failed to open" << std::endl;
    }

    return 0;
};

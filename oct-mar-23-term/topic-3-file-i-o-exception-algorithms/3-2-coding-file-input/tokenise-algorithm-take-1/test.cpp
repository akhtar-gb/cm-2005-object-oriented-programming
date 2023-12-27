#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// string csvLine = 'thing0,thing1,thing2' ## the string we are processing
// function which returns a vector of strings 
std::vector<std::string> tokensie(std::string csvLine, char seperator){

    // string vector tokens  ## stores the tokens    
    std::vector<std::string> tokens;

    // int start, end ## used to delineate the position of the tokens
    signed int start, end;
    std::string token;
    // start = csvLine.find_first_not_of(separator)
    start = csvLine.find_first_not_of(seperator, 0);

    // do
    do{
        // end = next 'separator' after start
        end = csvLine.find_first_of(seperator, start);
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

    // create from std::ifstream class a input file stream object csvFile and call a constructor with {} to open the file 
    std::ifstream csvFile{"20200317.csv"};

    // create a string variable to store a line from the file
    std::string line;

    // create a vector of strings to store the tokens
    std::vector<std::string> tokens;

    // check if the file is open
    if (csvFile.is_open()){
        std::cout << "File opened successfully" << std::endl;

        // while loop to read the file line by line
        while(std::getline(csvFile, line)){
            std::cout << ">> Line read " << line << std::endl;
            tokens = tokensie(line, ',');

            if (tokens.size() != 5){
                std::cout << ">> Error: line does not have 5 tokens" << std::endl;
                continue;
            }
            // else{
            //     std::cout << ">> Line has 5 tokens" << std::endl;
            //     // convert the tokens' strings to the correct data type
            //     double price = std::stod(tokens[3]);
            //     double amount = std::stod(tokens[4]);
            //     std::cout << ">> Price: " << price << std::endl;
            //     std::cout << ">> Amount: " << amount << std::endl;
            // }
            ;

            // try and catch block to catch the exception
            try{
                // convert the tokens' strings to the correct data type
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << price << ": " << price << std::endl;
                std::cout << amount << ": " << amount << std::endl;
            }
            catch(std::exception& e){
                std::cout << ">> Float conversion error: " << tokens[3] << std::endl;
                std::cout << ">> Float conversion error: " << tokens[4] << std::endl;
                // continue;
                break;
            };

            // // for loop to iterate over the tokens vector to print the tokens
            // for (std::string t : tokensie(line, ',')){
            //     std::cout << t << std::endl;
            // };
            std::cout << "------------------------" << std::endl;
        };
        csvFile.close();
    }
    else{
        std::cout << "File not opened successfully" << std::endl;
    };

    return 0;
};
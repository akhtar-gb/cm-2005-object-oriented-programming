#include <iostream>
#include <string>
#include <vector>

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

    // create a variable to store the tokens
    std::vector<std::string> tokens;

    // exmaple input string
    // std::string s = "thing0,thing1,thing2";
    std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";

    // call the function
    tokens = tokensie(s, ',');

    for (std::string& t : tokens){
        std::cout << t << std::endl;
    };

    return 0;
};
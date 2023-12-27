// Implement Tokensie Algorithm

/** The Pseudocode
 * string csvLine = 'thing,thing2,thing3'                                           ## the string we are processing and passed in as a parameter
 * string vector tokens                                                             ## stores the tokens
 * char separator = ','                                                             ## the character that separates the tokens is passed in as a parameter
 * int start, end                                                                   ## used to delineate the position of the tokens
 * start = csvLine.find_first_not_of(separator)
 * do
 * end = next 'separator' after start
 * if start == csvLine.length or start == end                                       ## nothing more to find
 * break
 * if end >= 0 ## we found the separator
 * token = csvLine.substr(start, end - start)                                       ## start, substring length
 * else
 * token = csvLine.substr(start, csvLine.length - start)                            ## end is invalid
 * add token to the end of the tokens vector
 * start = end + 1 ## move past this token
 * while (end > 0)                                                                  ## continue loop condition
*/

#include <iostream>
#include <string>
#include <vector>

/** function prototype
 * the purpose of the prototype is to tell the compiler that the function exists
 * a prototype defines the function name, return type and parameters
 * takes a string and a character as input
 * returns a vector of strings
 * the string is the csv line to be tokenised
 * the character is the separator
 * implementation includes the function name, return type, parameters and the body of the function
*/
std::vector<std::string> tokensie(std::string csvLine, char seperator); 

/** function implemenataion */
std::vector<std::string> tokensie(std::string csvLine, char seperator){
    
    std::vector<std::string> tokens;
    char separator = seperator;
    signed int start, end;

    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) break;

        std::string token;
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);

        start = end + 1;
    } 
    
    while (end != std::string::npos);

    return tokens;

};

int main(){

    // string variable that stores the input string
    // std::string s {"thing0,thing1,thing2"};

    /** test strings */
    // std::string s {"x, y, 90, (), R, test2"};
    std::string s {"2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869"};


    // a vector of string type named tokens to store the tokens when the tokensie function is called
    std::vector<std::string> tokens;

    // call the tokensie function and pass in the input string and the separator
    tokens = tokensie(s, ',');

    // for loop in range syntax to iterate by reference over the tokens vector
    // and each token is not to be modified
    for (const std::string& token : tokens){
        std::cout << token << std::endl;
    };

    // // return 0 to indicate the program ran successfully
    // return 0;
};



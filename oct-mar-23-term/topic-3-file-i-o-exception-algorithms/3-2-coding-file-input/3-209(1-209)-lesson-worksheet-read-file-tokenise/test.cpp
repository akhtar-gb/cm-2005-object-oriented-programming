// lesson worksheet: 3208_v2
// built on previous lecture in topic 3.1

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
#include <fstream>

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

    /* Test Block 1 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////// test the tokensie function //////

    // string variable that stores the input string
    std::string s {"one,two,three,four,five,six,seven,eight,nine,ten"};

    // a vector of string type named tokens to store the tokens when the tokensie function is called
    std::vector<std::string> tokens;

    // call the tokensie function and pass in the input string and the separator
    tokens = tokensie(s, ',');

    // for loop in range syntax to iterate by reference over the tokens vector
    // and each token is not to be modified
    for (const std::string& token : tokens){
        std::cout << token << std::endl;
    };
    
    */
    
    
    /* Testing/using the tokensie algorithm on the csv file //////////////////////////////////////////////////////////////////////////////////
    */

    // string variable that stores the filename - initialised with the filename
    std::string csvFilename {"20200317.csv"};
    // using an instance of the ifstream class to open the file and read from it
    // the ifstream class is in the fstream header file and is used to read from files
    std::ifstream csvFile {csvFilename};
    std::string line;

    /* Test Block 2 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ////// read a line from the file, tokensie the line and print the number of tokens //////
    
    // read a line from the file
    std::getline(csvFile, line);
    std::cout << "Line read: " << line << std::endl;
    std::vector<std::string> tokens = tokensie(line, ',');
    // print the size of the tokens vector
    std::cout << "Number of tokens: " << tokens.size() << std::endl;
    
    */

    if (csvFile.is_open()){
        std::cout << "File opened: " << csvFilename << std::endl;

        // iterate over the lines in the file
        while(getline(csvFile, line)){                                                  // while there are lines to read from the file
            std::vector<std::string> tokens = tokensie(line, ',');                      // tokenise the line by calling the tokensie function and store tokens in a string vector named tokens            
            // std::cout << "Number of tokens: " << tokens.size() << std::endl;            // print the size of the tokens vector
            
            // basic check if the line is valid - if the line has less then five tokens, the tokens vector will be empty
            if (tokens.size() != 5){
                std::cout << "Error: unexpected number of tokens" << line << std::endl;
                continue;
            };

            // handling exceptions on the string conversion to integer
            try{
                double amount = std::stod(tokens[3]);
                double price = std::stod(tokens[4]);
                std::cout << "Amount: " << amount << std::endl;
                std::cout << "Price: " << price << std::endl;
            }
            catch(const std::exception& e){
                std::cout << "Exception: " << e.what() << std::endl;
                // two ways to handle the exception
                // 1. continue with the next line
                // 2. break out of the loop
                // continue;
                break;
            };
        };
    }
    
    else{
        std::cout << "Error opening file: " << csvFilename << std::endl;
    };

    csvFile.close();

    return 0;
};



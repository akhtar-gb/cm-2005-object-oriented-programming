#include <iostream>
#include <string>

int main(){
    // try an double and create an exception
    double d;
    std::string s = "123.45";
    d = std::stod(s);

    std::cout << "d = " << d << std::endl;

    // try a value which cannot be converted to a double
    s = "123.45abc";
    d = std::stod(s);

    std::cout << "d = " << d << std::endl;

    // try nothing like a double and create an exception
    // catching exception will prevent the program from crashing
    // a design is required to handle the exception; whether the program should ignore the exception or handle it
    // have to decide where in the program to handle the exception and how to handle it
    // the operation throwing does not know how to handle the exception
    // so it throws the exception to the calling function
    s = "abc";
    
    /**
     * std::invalid_argument: stod: no conversion inherits from std::exception
     * so it can be caught by std exception handler - catch (const std::exception& e)
     * using const to prevent the exception from being modified
     * using & to pass by reference to avoid copying the exception
     * using e.what() to get the error message
     * what() is a member function of std::exception
    */

    try {
        d = std::stod(s);                                           
        std::cout << "d = " << d << std::endl;
    } catch (const std::exception& e) {                             
        std::cout << "Exception: " << e.what() << std::endl;
    };
};


#include <string>
#include <iostream>

int main(){
    std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
    std::cout << "length of s: " << s.length() << std::endl;

    // to change length lenghth
    s = "Somethign else";
    std::cout << "length of s: " << s.length() << std::endl;

    // standalone call to std::stod to convert a string to a double
    std::stod("10");
};
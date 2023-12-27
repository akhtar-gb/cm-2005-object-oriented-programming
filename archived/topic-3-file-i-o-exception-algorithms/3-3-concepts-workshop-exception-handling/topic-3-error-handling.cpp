#include <iostream>
#include <string>

int main(){

    double d = 0.0;
    std::string s = "aakjldsfghd";
    
    try{
        d = std::stod(s);
    }
    catch(const std::exception& e){

    };

    std::cout << "d: " << d << std::endl;

    return 0;
};
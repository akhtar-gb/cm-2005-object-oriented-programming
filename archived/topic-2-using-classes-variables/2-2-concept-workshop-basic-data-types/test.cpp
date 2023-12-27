#include <iostream>
#include <string>

enum class Colors {red, green, blue};

int main(){

    unsigned short i = 65536;
    unsigned long j = 4294967296;
    double d = 1.5;
    float f = 1.5f;
    std::string s = "Hello World!";

    std::cout << ">> size of unsigned short: " << sizeof(unsigned short) << " bytes" << std::endl;
    std::cout << "unsigned short variable i contains: " << i << std::endl;

    std::cout << ">> size of unsigned long: " << sizeof(unsigned long) << " bytes" << std::endl;
    std::cout << "unsigned long variable j contains: " << j << std::endl;

    std::cout << ">> size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "double variable d contains: " << d << std::endl;

    std::cout << ">> size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "float variable f contains: " << f << std::endl;

    std::cout << ">> size of Colors: " << sizeof(Colors) << " bytes" << std::endl;
    std::cout << "Colors::red contains: " << static_cast<int>(Colors::red) << std::endl;

    std::cout << ">> size of std::string: " << sizeof(std::string) << " bytes" << std::endl;
    std::cout << "std::string variable s contains: " << s << std::endl;

    return 0;
}
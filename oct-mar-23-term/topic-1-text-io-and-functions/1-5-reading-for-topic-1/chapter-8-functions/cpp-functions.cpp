#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <limits>

using namespace std;

// exponentiation function
double power (double x, int n){
    double result;
    if (n >= 0)
        for (int i = 1; i <= n; ++i)
            result *= x;
    else
        for (int i = 1; i <= -n; ++i)
            result /= x;
    return result;
};

// main function
int main(){

    double number = 3.0;
    const double result = power(number, 2);

    std::cout << fixed << result << std::endl;

};
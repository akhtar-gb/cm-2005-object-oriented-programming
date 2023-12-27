#include <iostream>

// function prototypes
void print_hello_world();
int average(int x, int y);
float sum(float x, float y);

// main function
int main() {
    print_hello_world();
    average(2, 4);
    sum(2.5, 4.5);
};


// function definitions
void print_hello_world() {
    std::cout << "Hello, world!" << std::endl;
};

/** compute the average of x and y */
int average(int x, int y){
    int z = (x + y) / 2;
    std::cout << "The average of " << x << " and " << y << " is " << z << std::endl;
    return z;
}

/** compute sum of two floats */
float sum(float x, float y){
    float z = x + y;
    std::cout << "The sum of " << x << " and " << y << " is " << z << std::endl;
    return z;
}
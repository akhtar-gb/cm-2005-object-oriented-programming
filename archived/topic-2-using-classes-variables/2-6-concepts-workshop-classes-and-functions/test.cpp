#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Vec3D.h"

int main()
{
    Vec3D myVec;
    myVec.x = 10;
    myVec.y = 12;
    myVec.z = 25;

    std::cout << "myVec.x: " << myVec.x << std::endl;
    std::cout << "myVec.y: " << myVec.y << std::endl;
    std::cout << "myVec.z: " << myVec.z << std::endl;
    
    int len = myVec.getLength();
    std::cout << "myVec length: " << len << std::endl;
    return 0;
}
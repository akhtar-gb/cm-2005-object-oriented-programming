#include "Vec3D.h"
#include <cmath>


// Vec3D::Vec3D()
// {

// }

// Vec3D::~Vec3D()
// {

// }

int Vec3D::getLength()
{
    return std::sqrt(x*x + y*y + z*z);
}

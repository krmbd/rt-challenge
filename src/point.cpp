#include "point.hpp"

bool operator==(Point lhs, Point rhs)
{
    return AreAlmostEqual(lhs.x, rhs.x) && AreAlmostEqual(lhs.y, rhs.y) && AreAlmostEqual(lhs.z, rhs.z);
}

std::ostream& operator<<(std::ostream& ostream, Point point)
{
    ostream << "{ " << point.x << ", " << point.y << ", " << point.z << " }";
    return ostream;
}

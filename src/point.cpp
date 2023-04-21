#include "point.hpp"
#include "vector.hpp"

bool operator==(Point lhs, Point rhs)
{
    return AreAlmostEqual(lhs.x, rhs.x) && AreAlmostEqual(lhs.y, rhs.y) && AreAlmostEqual(lhs.z, rhs.z);
}

std::ostream& operator<<(std::ostream& ostream, Point point)
{
    ostream << "{ " << point.x << ", " << point.y << ", " << point.z << " }";
    return ostream;
}

Point operator+(Point point, Vector vector)
{
    return Point{ point.x + vector.x, point.y + vector.y, point.z + vector.z };
}

Point operator-(Point point, Vector vector)
{
    return Point{ point.x - vector.x, point.y - vector.y, point.z - vector.z };
}

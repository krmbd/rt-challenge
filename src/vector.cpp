#include "vector.hpp"

bool operator==(Vector lhs, Vector rhs)
{
    return AreAlmostEqual(lhs.x, rhs.x) && AreAlmostEqual(lhs.y, rhs.y) && AreAlmostEqual(lhs.z, rhs.z);
}

std::ostream& operator<<(std::ostream& ostream, Vector vector)
{
    ostream << "{ " << vector.x << ", " << vector.y << ", " << vector.z << " }";
    return ostream;
}

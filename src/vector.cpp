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

Vector operator+(Vector vector1, Vector vector2)
{
    return Vector{ vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z };
}

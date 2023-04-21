#include "vector.hpp"
#include "point.hpp"

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

Vector operator-(Vector vector1, Vector vector2)
{
    return Vector{ vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z };
}

Vector operator-(Point point1, Point point2)
{
    return Vector{ point1.x - point2.x, point1.y - point2.y, point1.z - point2.z };
}

Vector operator-(Vector vector)
{
    return Vector{ -vector.x, -vector.y, -vector.z };
}

Vector operator*(double scalar, Vector vector)
{
    return Vector{ scalar * vector.x, scalar * vector.y, scalar * vector.z };
}

Vector operator/(Vector vector, double scalar)
{
    return (1 / scalar) * vector;
}

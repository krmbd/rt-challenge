#include <cmath>

#include "point.hpp"
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

Vector operator+(Vector lhs, Vector rhs)
{
    return Vector{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

Vector operator-(Vector lhs, Vector rhs)
{
    return Vector{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
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

double Magnitude(Vector vector)
{
    return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

double Dot(Vector lhs, Vector rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vector Normalize(Vector vector)
{
    return vector / Magnitude(vector);
}

Vector Cross(Vector lhs, Vector rhs)
{
    return Vector{ lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x };
}

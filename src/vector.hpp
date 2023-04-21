#pragma once

#include <iostream>

#include "util.hpp"

class Vector
{
public:
    Vector() = delete;
    Vector(double x, double y, double z) : x{ x }, y{ y }, z{ z } {}

    const double x{};
    const double y{};
    const double z{};
    static constexpr int w{ 0 };
};

inline bool operator==(const Vector lhs, const Vector rhs)
{
    return AreAlmostEqual(lhs.x, rhs.x) && AreAlmostEqual(lhs.y, rhs.y) && AreAlmostEqual(lhs.z, rhs.z);
}

inline std::ostream& operator<<(std::ostream& ostream, const Vector vector)
{
    ostream << "{ " << vector.x << ", " << vector.y << ", " << vector.z << " }";
    return ostream;
}

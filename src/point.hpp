#pragma once

#include <ostream>

#include "util.hpp"

class Point
{
public:
    Point() = delete;
    Point(double x, double y, double z) : x{ x }, y{ y }, z{ z } {}

    const double x{};
    const double y{};
    const double z{};
    static constexpr int w{ 1 };
};

inline bool operator==(const Point lhs, const Point rhs)
{
    return AreAlmostEqual(lhs.x, rhs.x) && AreAlmostEqual(lhs.y, rhs.y) && AreAlmostEqual(lhs.z, rhs.z);
}

inline std::ostream& operator<<(std::ostream& ostream, const Point point)
{
    ostream << "{ " << point.x << ", " << point.y << ", " << point.z << " }";
    return ostream;
}

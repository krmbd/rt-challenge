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

bool operator==(Point lhs, Point rhs);
std::ostream& operator<<(std::ostream& ostream, Point point);

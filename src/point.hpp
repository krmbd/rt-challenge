#pragma once

#include <ostream>

#include "util.hpp"

class Vector;

class Point
{
public:
    Point() = delete;
    Point(double x, double y, double z) : x{ x }, y{ y }, z{ z } {}

    double x{};
    double y{};
    double z{};
    static constexpr int w{ 1 };
};

bool operator==(Point lhs, Point rhs);
std::ostream& operator<<(std::ostream& ostream, Point point);

Point operator+(Point point, Vector vector);
Point operator-(Point point, Vector vector);

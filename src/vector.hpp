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

bool operator==(Vector lhs, Vector rhs);
std::ostream& operator<<(std::ostream& ostream, Vector vector);

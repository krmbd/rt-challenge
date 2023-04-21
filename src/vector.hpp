#pragma once

#include <iostream>

#include "util.hpp"

class Point;

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

Vector operator+(Vector lhs, Vector rhs);
Vector operator-(Vector lhs, Vector rhs);
Vector operator-(Point point1, Point point2);
Vector operator-(Vector vector);
Vector operator*(double scalar, Vector vector);
Vector operator/(Vector vector, double scalar);

double Magnitude(Vector vector);
double Dot(Vector lhs, Vector rhs);
Vector Normalize(Vector vector);
Vector Cross(Vector lhs, Vector rhs);

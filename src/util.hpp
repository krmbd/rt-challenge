#pragma once

#include <cmath>

const double EPISLON = 0.0001;

inline bool AreAlmostEqual(double lhs, double rhs)
{
    return std::fabs(lhs - rhs) < EPISLON;
}

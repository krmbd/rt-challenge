#include <catch2/catch_test_macros.hpp>

#include "point.hpp"
#include "util.hpp"

// NOLINTBEGIN(cert-err58-cpp)
TEST_CASE("A Point is a tuple with w = 1", "[point][tuple][ch1]")
{
    REQUIRE(Point::w == 1);
}

TEST_CASE("Output stream operator of a Point", "[point]")
{
    const Point point{ 1, 2, 3 };

    std::ostringstream stream;
    stream << point;

    std::string expectedOutput = "{ 1, 2, 3 }";
    std::string actualOutput = stream.str();

    REQUIRE(expectedOutput == actualOutput);
}

TEST_CASE("Equality for two almost-equal Points", "[point]")
{
    const Point point1{ 1, 2, 3 };
    const Point point2{ 1, 2, 3 - EPSILON / 2 };

    REQUIRE(point1 == point2);
}

TEST_CASE("Equality for two slightly different Points", "[point]")
{
    const Point point1{ 1, 2, 3 };
    const Point point2{ 1, 2, 3 - EPSILON * 2 };

    REQUIRE(point1 != point2);
}
// NOLINTEND(cert-err58-cpp)

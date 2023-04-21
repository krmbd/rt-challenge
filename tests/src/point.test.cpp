#include <catch2/catch_test_macros.hpp>

#include "point.hpp"
#include "util.hpp"
#include "vector.hpp"

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

TEST_CASE("Adding a Vector to a Point returns a Point", "[point][vector][tuple][ch1]")
{
    const Point point{ 3, -2, 5 };
    const Vector vector{ -2, 3, 1 };

    const Point expectedResult = { 1, 1, 6 };
    const Point actualResult = point + vector;

    REQUIRE(expectedResult == actualResult);
}

TEST_CASE("Substracting a Vector from a Point returns a Point", "[point][vector][tuple][ch1]")
{
    const Point point{ 3, 2, 1 };
    const Vector vector{ 5, 6, 7 };

    const Point expectedResult = { -2, -4, -6 };
    const Point actualResult = point - vector;

    REQUIRE(expectedResult == actualResult);
}
// NOLINTEND(cert-err58-cpp)

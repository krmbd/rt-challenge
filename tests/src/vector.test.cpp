#include <catch2/catch_test_macros.hpp>

#include "point.hpp"
#include "util.hpp"
#include "vector.hpp"

// NOLINTBEGIN(cert-err58-cpp)
TEST_CASE("A Vector is a tuple with w = 0", "[vector][tuple][ch1]")
{
    REQUIRE(Vector::w == 0);
}

TEST_CASE("Output stream operator of a Vector", "[vector][tuple]")
{
    const Vector vector{ -4, -5, -6 };

    std::ostringstream stream;
    stream << vector;

    std::string expectedOutput = "{ -4, -5, -6 }";
    std::string actualOutput = stream.str();

    REQUIRE(expectedOutput == actualOutput);
}

TEST_CASE("Equality for two almost-equal Vectors", "[vector]")
{
    const Vector vector1{ 1, 2, 3 };
    const Vector vector2{ 1, 2, 3 - EPSILON / 2 };

    REQUIRE(vector1 == vector2);
}

TEST_CASE("Equality for two slightly different Vectors", "[vector]")
{
    const Vector vector1{ 1, 2, 3 };
    const Vector vector2{ 1, 2, 3 - EPSILON * 2 };

    REQUIRE(vector1 != vector2);
}

TEST_CASE("Adding a Vector to a Vector returns a Vector", "[vector][tuple][ch1]")
{
    const Vector vector1{ -3, 2, -5 };
    const Vector vector2{ -2, 3, 1 };

    const Vector expectedResult = { -5, 5, -4 };
    const Vector actualResult = vector1 + vector2;

    REQUIRE(expectedResult == actualResult);
}

TEST_CASE("Substracting a Vector from a Vector returns a Vector", "[vector][tuple][ch1]")
{
    const Vector vector1{ 3, 2, 1 };
    const Vector vector2{ 5, 6, 7 };

    const Vector expectedResult = { -2, -4, -6 };
    const Vector actualResult = vector1 - vector2;

    REQUIRE(expectedResult == actualResult);
}

TEST_CASE("Substracting a Point from a Point returns a Vector", "[point][vector][tuple][ch1]")
{
    const Point point1{ 3, 2, 1 };
    const Point point2{ 5, 6, 7 };

    const Vector expectedResult = { -2, -4, -6 };
    const Vector actualResult = point1 - point2;

    REQUIRE(expectedResult == actualResult);
}
// NOLINTEND(cert-err58-cpp)
